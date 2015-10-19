////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-19 19:32:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <algorithm>
using namespace std;
#define M 10001
int main()
{
	int t,n;
	char dp[M];
	int i,j,k;
	int cost[3]={150,200,350};
	memset(dp,0,M);
	for(j=0;j<=M;j+=cost[0])
		dp[j]=1;

	for(i=1;i<3;i++)
	{
		for(j=0;j<=M;j++)
		{
			if(dp[j])
			{
				for(k=j+cost[i];k<=M;k+=cost[i])
					dp[k]=1;
			}
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(k=n;k>=0;k--)
			if(dp[k])
				break;
		printf("%d\n",n-k);
	}
	return 0;
}