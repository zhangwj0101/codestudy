////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-23 14:41:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
using namespace std;

int Hash[8][8];
int map[8][8];
int Dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int ax,ay;
struct step
{
	int x,y;
	int time,steps;
	void set(int nx,int ny,int nt,int ns);
};
void step::set(int nx,int ny,int nt,int ns){
	x=nx,y=ny,time=nt,steps=ns;
}
queue<step> Path;
int Bfs(int sx,int sy,int ex,int ey)
{
	memset(Hash,0,sizeof(Hash));
	while(!Path.empty()) Path.pop();
	step temp;
	temp.set(sx,sy,6,0);
	Hash[sx][sy]=6;
	Path.push(temp);
	while(!Path.empty()){
		for(int i=0;i<4;i++){
			int tx=Path.front().x+Dir[i][0],ty=Path.front().y+Dir[i][1];
			int tt=Path.front().time-1,ts=Path.front().steps+1;
			if(tt>Hash[tx][ty]&&tx>=0&&tx<ax&&ty>=0&&ty<ay){
				if(map[ty][tx]==0) continue;
				else{
					if(ty==ey&&tx==ex) return ts;
					if(map[ty][tx]==4) tt=6;
					temp.set(tx,ty,tt,ts);
					Hash[tx][ty]=tt;
					if(tt==1) break;
					Path.push(temp);
				}
			}
		}
		Path.pop();
	}
	return -1;
}

void main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int sx,sy,ex,ey;
		scanf("%d%d",&ay,&ax);
		for(int i=0;i<ay;i++)
			for(int j=0;j<ax;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]==2){
					sx=j;sy=i;
					map[i][j]=1;
				}else if(map[i][j]==3){
					ex=j;ey=i;
					map[i][j]=1;
				}
			}
		int ans=Bfs(sx,sy,ex,ey);
		printf("%d\n",ans);
	}
}