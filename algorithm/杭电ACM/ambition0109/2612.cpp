////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-08 14:44:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2612
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
using namespace std;

char map[201][201];
bool Hash[2][201][201];
int yx,yy,ax,ay;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct step{
	int x,y,t; bool k;
	void set(int nx,int ny,int nt,bool nk){
		x=nx,y=ny,t=nt;k=nk;
	}
};
inline bool Check(int x,int y){
	if(x<ax&&x>=0&&y<ay&&y>=0){
		if(map[y][x]!='#'){
			return true;
		}
	}
	return false;
}
int Bfs(){
	queue<step> steps;
	memset(Hash,false,sizeof(Hash));
	step temp;
	temp.set(yx,yy,0,false);
	steps.push(temp);
	Hash[0][yy][yx]=true;
	while(!steps.empty()){
		int tx=steps.front().x;
		int ty=steps.front().y;
		int tt=steps.front().t;
		bool tk=steps.front().k;
		steps.pop();
		for(int i=0;i<4;i++){
			int ttx=tx+dir[i][0];
			int tty=ty+dir[i][1];
			if(!Check(ttx,tty)) continue;
			if(Hash[tk][tty][ttx]) continue;
			Hash[tk][tty][ttx]=true;
			if(tk) Hash[tk^1][tty][ttx]=true;
			if(tk&&map[tty][ttx]=='M') return tt+1;
			if(!tk&&map[tty][ttx]=='@'){
				tk=true;
				Hash[tk][tty][ttx]=true;
			}
			temp.set(ttx,tty,tt+1,tk);
			steps.push(temp);
		}
	}
	return -1;
}

int main()
{
	while(scanf("%d%d",&ay,&ax)!=EOF){
		for(int i=0;i<ay;i++){
			scanf("%s",map[i]);
			for(int j=0;j<ax;j++){
				if(map[i][j]=='Y'){
					yx=j;yy=i;
					break;
				}
			}
		}
		printf("%d\n",Bfs()*11);
	}
}