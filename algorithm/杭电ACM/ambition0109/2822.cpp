////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-29 10:30:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2822
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:9484KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
using namespace std;

struct step
{
	int x,y,t;
	void set(int nx,int ny,int nt){
		x=nx;y=ny;t=nt;
	}
};
struct compare
{
	bool operator() (const step &a,const step &b){
		return a.t>b.t;
	}
};
int ax,ay,sx,sy,ex,ey;
char map[1001][1001];
bool Hash[1001][1001];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int Bfs()
{
	priority_queue<step,vector<step>,compare> steps;
	memset(Hash,true,sizeof(Hash));
	step temp;
	temp.set(sx,sy,0);
	steps.push(temp);
	Hash[sy][sx]=false;
	while(!steps.empty()){
		int tx=steps.top().x,ty=steps.top().y;
		int tt=steps.top().t;steps.pop();
		for(int i=0;i<4;i++){
			int ttx=tx+dir[i][0],tty=ty+dir[i][1];
			if(ttx==ex&&tty==ey) return tt;
			int ttt=tt;
			if(ttx>=0&&ttx<ax&&tty>=0&&tty<ay){
				if(!Hash[tty][ttx]) continue;
				if(map[tty][ttx]=='.') ttt++;
				temp.set(ttx,tty,ttt);
				steps.push(temp);
				Hash[tty][ttx]=false;
			}
		}
	}
	return -1;
}

void main()
{
	while(scanf("%d%d",&ay,&ax),ay||ax){
		for(int i=0;i<ay;i++)
			scanf("%s",map[i]);
		scanf("%d%d%d%d",&sy,&sx,&ey,&ex);
		sy--;sx--;ey--;ex--;
		if(sy==ey&&sx==ex) printf("0\n");
		else printf("%d\n",Bfs());
	}
}