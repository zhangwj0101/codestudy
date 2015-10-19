////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-28 18:06:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2364
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct step{
	int x,y,t,dir;
	void set(int nx,int ny,int nt,int nd){
		x=nx;y=ny;t=nt;dir=nd;
	}
};
struct point{
	int x,y;
};

char map[85][85];
bool Hash[85][85][4];
int Dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int sx,sy,ax,ay,le;
int Bfs()
{
	queue<step> steps;
	memset(Hash,false,sizeof(Hash));
	step temp;
	temp.set(sx,sy,0,0);
	steps.push(temp);
	Hash[sy][sx][0]=true;
	Hash[sy][sx][2]=true;
	temp.set(sx,sy,0,1);
	steps.push(temp);
	Hash[sy][sx][1]=true;
	Hash[sy][sx][0]=true;
	while(!steps.empty()){
		int tx=steps.front().x;
		int ty=steps.front().y;
		int tt=steps.front().t;
		int td=steps.front().dir;
		if(tx==ax-1||ty==ay-1||tx==0||ty==0)
			return tt;
		steps.pop();
		int ttd1=(td+1)%4,ttd2=(td+3)%4;
		int ttx=tx+Dir[td][0];
		int tty=ty+Dir[td][1];
		int ttx1=tx+Dir[ttd1][0];
		int tty1=ty+Dir[ttd1][1];
		int ttx2=tx+Dir[ttd2][0];
		int tty2=ty+Dir[ttd2][1];
		if(map[tty1][ttx1]!='#'||map[tty2][ttx2]!='#'){
			if(map[tty1][ttx1]!='#'&&!Hash[tty1][ttx1][ttd1]){
				temp.set(ttx1,tty1,tt+1,ttd1);
				steps.push(temp);
				Hash[tty1][ttx1][ttd1]=true;
			}
			if(map[tty2][ttx2]!='#'&&!Hash[tty2][ttx2][ttd2]){
				temp.set(ttx2,tty2,tt+1,ttd2);
				steps.push(temp);
				Hash[tty2][ttx2][ttd2]=true;
			}
		}else{
			if(map[tty][ttx]!='#'&&!Hash[tty][ttx][td]){
				temp.set(ttx,tty,tt+1,td);
				steps.push(temp);
				Hash[tty][ttx][td]=true;
			}
		}
	}
	return -1;
}

void main()
{
	int t;cin>>t;
	while(t--){
		scanf("%d%d",&ay,&ax);
		for(int i=0;i<ay;i++){
			scanf("%s",map[i]);
			for(int j=0;j<ax;j++){
				if(map[i][j]=='@'){
					sx=j;sy=i;
				}
			}
		}
		if(sx==ax-1||sx==0||sy==ay-1||sy==0){
			printf("0\n");continue;
		}
		printf("%d\n",Bfs());
	}
}