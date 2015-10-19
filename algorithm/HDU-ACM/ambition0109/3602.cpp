////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-12 17:17:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3602
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int dp[10010][2];
int num,val;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		int Ans=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&num,&val); num+=1;
			for(int j=10000;j>=val;j--){
				if( num<=k && dp[j-val][0]!=0 ){
					int s,p;
					if(dp[j-val][1]+num>k){
						s=dp[j-val][0]+1;
						p=num;
					}else{
						s=dp[j-val][0];
						p=dp[j-val][1]+num;
					}
					if(s>m) continue;
					if(dp[j][0]==0||s<dp[j][0]||(s==dp[j][0]&&p<dp[j][1])){
						dp[j][0]=s; dp[j][1]=p;
						if(Ans<j) Ans=j;
					}
				}
			}
		}
		printf("%d\n",Ans);
	}
}