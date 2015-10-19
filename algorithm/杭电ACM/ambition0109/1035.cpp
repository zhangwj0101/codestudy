////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-05 18:41:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

char Mmap[15][15];
int Step[15][15];
int main()
{
	int n,m,k;
	while(scanf("%d%d",&n,&m),n||m){
		scanf("%d",&k);
		memset(Step,-1,sizeof(Step));
		for(int i=1;i<=n;i++){
			scanf("%s",Mmap[i]+1);
		}
		int x=1,y=k,s=1;
		Step[x][y]=0;
		while(1){
			if(Mmap[x][y]=='W') y--;
			else if(Mmap[x][y]=='S') x++;
			else if(Mmap[x][y]=='E') y++;
			else if(Mmap[x][y]=='N') x--;
			if(x==0||y==0||x==n+1||y==m+1){
				printf("%d step(s) to exit\n",s);
				break;
			}
			if(Step[x][y]!=-1){
				printf("%d step(s) before a loop of %d step(s)\n",Step[x][y],s-Step[x][y]);
				break;
			}
			Step[x][y]=s++;
		}
	}
}