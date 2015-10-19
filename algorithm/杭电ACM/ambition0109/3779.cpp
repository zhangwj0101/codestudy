////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-09 19:12:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3779
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:4220KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int nna[1005],nnb[1005],na,nb;
int nt[2010];
int dp[1005][1005];
int dfs(int a,int b){
	if(a==na&&b==nb) return 1;
//	printf("= %d %d\n",a,b);
	if(a<na&&nna[a]==nt[a+b]){
		if(dp[a+1][b]==-1){
			dp[a+1][b]=dfs(a+1,b);
		}
		if(dp[a+1][b]) return 1;
	}
	if(b<nb&&nnb[b]==nt[a+b]){
		if(dp[a][b+1]==-1){
			dp[a][b+1]=dfs(a,b+1);
		}
		if(dp[a][b+1]) return 1;
	}
	return 0;
}

int main(){
	while(~scanf("%d%d",&na,&nb)&&(na||nb)){
		for(int i=0;i<na;i++){
			scanf("%d",&nna[i]);
		}
		for(int i=0;i<nb;i++){
			scanf("%d",&nnb[i]);
		}
		for(int i=0;i<na+nb;i++){
			scanf("%d",&nt[i]);
		}
		
		memset(dp,-1,sizeof(dp));
		puts(dfs(0,0)?"possible":"not possible");
	}
}