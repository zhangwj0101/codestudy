////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-25 15:51:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2757
////Problem Title: 
////Run result: Accept
////Run time:1843MS
////Run memory:8272KB
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

struct mycomparison {
	bool operator () (const step &a,const step &b) const{
		return a.t>b.t;
	}
};
int map[1001][1001];
priority_queue<step,vector<step>,mycomparison> steps;
int sx,sy,ex,ey,ax,ay;
int Hash[1001][1001];
int Dir[8][2]={{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};

inline void scan_d(int &num)
{
	char in;
	in=getchar();
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
}

int Bfs()
{
	while(!steps.empty()) steps.pop();
	memset(Hash,1,sizeof(Hash));
	step temp;
	Hash[sy][sx]=0;
	temp.set(sx,sy,0);
	steps.push(temp);
	while(!steps.empty()){
		int tx=steps.top().x,ty=steps.top().y;
		if(tx==ex&&ty==ey) return steps.top().t;
		for(int i=0;i<8;i++){
			int ttx=tx+Dir[i][0],tty=ty+Dir[i][1];
			int tt=steps.top().t+1;
			if(map[ty][tx]==i) tt-=1;
			if(ttx>=0&&ttx<ax&&tty>=0&&tty<ay)
			if(Hash[tty][ttx]>tt){
				temp.set(ttx,tty,tt);
				Hash[tty][ttx]=tt;
				steps.push(temp);
			}
		}
		steps.pop();
	}
	return -1;
}

void main()
{
	while(scanf("%d%d",&ay,&ax)!=EOF){
		for(int i=0;i<ay;i++)
			for(int j=0;j<ax;j++)
				scan_d(map[i][j]);
		int n;
		scanf("%d",&n);
		while(n--){
			scanf("%d%d%d%d",&sy,&sx,&ey,&ex);
			if(sx==ex&&sy==ey){
				printf("0\n");
				continue;
			}
			sx--,sy--,ex--,ey--;
			printf("%d\n",Bfs());
		}
	}
}