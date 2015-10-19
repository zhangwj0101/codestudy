////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-23 11:30:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1421
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:8040KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define dou(x) (x*x)

int dp[2000][1000];
int main()
{
    int n,m,i,j,t,num[2000];
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++){
            scanf("%d",&num[i]);
		}
        sort(num+1,num+n+1);
		memset(dp,0,sizeof(dp));
		dp[2][1]=dou((num[2]-num[1]));
		for(i=3;i<=n;i++) {
			for(j=1;j<=i/2;j++) {
				if(i==(j<<1)) {
					dp[i][j]=dou((num[i]-num[i-1]))+dp[i-2][j-1];
				} else {
					t=dou((num[i]-num[i-1]))+dp[i-2][j-1];
					dp[i][j]=dp[i-1][j]>t?t:dp[i-1][j];
				}
			}
		}
		printf("%d\n",dp[n][m]);
    }
}
