////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-31 15:44:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2579
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<queue>
using namespace std;

struct step{
	int x,y,t;
	void set(int nx,int ny,int nt){
		x=nx;y=ny;t=nt;
	}
};
struct compare{
	bool operator() (const step& a,const step& b){
		return a.t>b.t;
	}
};
char map[101][101];
bool Hash[101][101][11];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int ax,ay,sx,sy,ex,ey,k;
int Bfs(){
	priority_queue<step,vector<step>,compare> steps;
	for(int i=0;i<ay;i++)
		for(int j=0;j<ax;j++)
			memset(Hash[i][j],false,sizeof(Hash[i][j]));
	step temp;
	temp.set(sx,sy,0);
	steps.push(temp);
	Hash[sy][sx][0]=true;
	while(!steps.empty()){
		int tx,ty,tt;
		tx=steps.top().x;
		ty=steps.top().y;
		tt=steps.top().t+1;
		steps.pop();
		for(int i=0;i<4;i++){
			int ttx=tx+dir[i][0];
			int tty=ty+dir[i][1];
			if(ttx==ex&&tty==ey) return tt;
			int ttt=tt%k;
			if(ttx>=0&&ttx<ax&&tty>=0&&tty<ay){
				if(map[tty][ttx]=='#'&&ttt) continue;
				if(Hash[tty][ttx][ttt]) continue;
				temp.set(ttx,tty,tt);
				steps.push(temp);
				Hash[tty][ttx][ttt]=true;
			}
		}
	}
	return -1;
}

void main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&ay,&ax,&k);
		sx=sy=ex=ey=-1;
		for(int i=0;i<ay;i++){
			scanf("%s",map[i]);
			if(sx==-1||ex==-1)
			for(int j=0;j<ax;j++){
				if(map[i][j]=='Y'){
					sx=j;sy=i;
				}else if(map[i][j]=='G'){
					ex=j;ey=i;
				}
			}
		}
		int ans=Bfs();
		if(ans==-1) printf("Please give me another chance!\n");
		else printf("%d\n",ans);
	}
}