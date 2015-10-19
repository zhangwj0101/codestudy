////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-25 18:45:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1026
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:372KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
using namespace std;

struct step{
	int x,y,t;
	void set(int nx,int ny,int nt){
		x=nx;y=ny;t=nt;
	}
};
struct compare{
	bool operator ()(const step& a,const step& b){
		return a.t>b.t;
	}
};
char map[105][105];
bool Hash[105][105];
step pre[105][105];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int ax,ay;
int Bfs()
{
	priority_queue<step,vector<step>,compare> steps;
	memset(Hash,true,sizeof(Hash));
	step temp;
	temp.set(ax-1,ay-1,0);
	pre[ax-1][ay-1].t=0;
	if(map[ay-1][ax-1]!='.'){
		temp.t+=map[ay-1][ax-1]-'0';
		pre[ax-1][ay-1].t+=map[ay-1][ax-1]-'0';
	}
	Hash[ay-1][ax-1]=false;
	steps.push(temp);
	while(!steps.empty()){
		int tx=steps.top().x,ty=steps.top().y,tt=steps.top().t;
		if(tx==0&&ty==0) return tt;
		steps.pop();
		for(int i=0;i<4;i++){
			int ttx=tx+dir[i][0],tty=ty+dir[i][1];
			if(ttx>=0&&ttx<ax&&tty>=0&&tty<ay)
				if(Hash[tty][ttx]&&map[tty][ttx]!='X'){
					pre[ttx][tty].set(tx,ty,0);
					Hash[tty][ttx]=false;
					temp.set(ttx,tty,tt+1);
					if(map[tty][ttx]!='.'){
						temp.t+=map[tty][ttx]-'0';
						pre[ttx][tty].t+=map[tty][ttx]-'0';
					}
					steps.push(temp);
				}
		}
	}
	return -1;
}

void main()
{
	while(~scanf("%d%d",&ay,&ax)){
		for(int i=0;i<ay;i++)
			scanf("%s",map[i]);
		if(map[ay-1][ax-1]=='X'){
			printf("God please help our poor hero.\n");
		}else{
			int ans=Bfs();
			if(ans==-1){
				printf("God please help our poor hero.\n");
			}else{
				printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
				int fx=0,fy=0,tx,ty;
				for(int i=1;i<=ans;i++){
					tx=pre[fx][fy].x;ty=pre[fx][fy].y;int tt=pre[tx][ty].t;
					printf("%ds:(%d,%d)->(%d,%d)\n",i,fy,fx,ty,tx);
					if(tt){
						for(int j=0;j<tt;j++){
							printf("%ds:FIGHT AT (%d,%d)\n",++i,ty,tx);
						}
					}
					fx=tx;fy=ty;
				}
			}
		}
		printf("FINISH\n");
	}
}