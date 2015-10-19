////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-08 20:42:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2102
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,time;
char Map[2][12][12];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool Dfs(int x,int y,int t,int f){
	//printf("-- %d %d %d %d\n",f,x,y,t);
	if(t==time) return false;
	for(int i=0;i<4;i++){
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		int tt=t+1,tf=f;
		if(tx<1||ty<1||tx>n||ty>m) continue;
		if(Map[tf][tx][ty]=='#') tf^=1;
		if(Map[tf][tx][ty]=='*'||Map[tf][tx][ty]=='#') continue;
		if(Map[tf][tx][ty]=='P') return true;
		Map[tf][tx][ty]='*';
		if(Dfs(tx,ty,tt,tf)) return true;
		Map[tf][tx][ty]='.';
	}
	return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&time);
		for(int i=1;i<=n;i++){
			scanf("%s",Map[0][i]+1);
		}
		for(int i=1;i<=n;i++){
			scanf("%s",Map[1][i]+1);
		}
		//printf("## %d %d %d\n",sx,sy,tf);
		puts(Dfs(1,1,0,0)?"YES":"NO");
	}
}