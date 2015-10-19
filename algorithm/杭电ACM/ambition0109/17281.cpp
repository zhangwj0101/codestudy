////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-26 15:22:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1728
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:360KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
using namespace std;

inline void cin_c(char &ch)
{
	ch=getchar();
	while(ch!='.'&&ch!='*')
		ch=getchar();
}
struct step{
	int x,y,t;
	void set(int nx,int ny,int nt){
		x=nx;y=ny;t=nt;
	}
};

char map[105][105];
bool Hash[105][105][2];
int ax,ay,sx,sy,ex,ey,at;
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool Bfs()
{
	queue<step> steps;
	memset(Hash,true,sizeof(Hash));
	step temp;
	temp.set(sx,sy,-1);
	Hash[sy][sx][0]=false;
	Hash[sy][sx][1]=false;
	steps.push(temp);
	while(!steps.empty()){
		int tx=steps.front().x,ty=steps.front().y,tt=steps.front().t;
		for(int i=0;i<4;i++){
			int ttx=tx+dir[i][0],tty=ty+dir[i][1];
			if(tt>=at) return false; 
			while(ttx>=0&&ttx<ax&&tty>=0&&tty<ay&&map[tty][ttx]!='*'){
				if(!Hash[tty][ttx][i%2]) break;
				if(ttx==ex&&tty==ey) return true;
				Hash[tty][ttx][i%2]=false;
				temp.set(ttx,tty,tt+1);
				steps.push(temp);
				ttx+=dir[i][0],tty+=dir[i][1];
			}
		}
		steps.pop();
	}
	return false;
}

int main()
{
	int c;cin>>c;
	while(c--){
		cin>>ay>>ax;
		for(int i=0;i<ay;i++)
			for(int j=0;j<ax;j++)
				cin_c(map[i][j]);
		cin>>at>>sx>>sy>>ex>>ey;
		if(sx==ex&&sy==ey) cout<<"yes"<<endl;
		else{
			sy--;sx--;ey--;ex--;
			if(Bfs()) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
}