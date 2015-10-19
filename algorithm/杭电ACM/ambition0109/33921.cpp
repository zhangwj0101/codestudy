////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-11 11:00:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3392
////Problem Title: 
////Run result: Accept
////Run time:1390MS
////Run memory:512KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory>
#include<algorithm>
using namespace std;

int compare(const void *a,const void *b)
{
	return (*(double*)a>*(double*)b?1:-1);
}
double h1[10001],h2[10001];
double dp[2][10001];
void main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n||m)
	{
		if(n>m){
			for(int i=0;i<n;i++)
				scanf("%lf",&h2[i]);
			for(int i=0;i<m;i++)
				scanf("%lf",&h1[i]);
			n^=m;m^=n;n^=m;
		}else{
			for(int i=0;i<n;i++)
				scanf("%lf",&h1[i]);
			for(int i=0;i<m;i++)
				scanf("%lf",&h2[i]);
		}
		if(m-n>100) continue;
		qsort(h1,n,sizeof(double),compare);
		qsort(h2,m,sizeof(double),compare);
		memset(dp[0],0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=i;j<m-n+i+1;j++){
				if(i==j) dp[1][j+1]=dp[0][j]+fabs(h1[i]-h2[j]);
				else{
					if(dp[1][j]<dp[0][j]+fabs(h1[i]-h2[j]))
						dp[1][j+1]=dp[1][j];
					else dp[1][j+1]=dp[0][j]+fabs(h1[i]-h2[j]);
				}
			}
			copy(dp[1]+i,dp[1]+m-n+i+2,dp[0]+i);
		}
		printf("%.6lf\n",dp[1][m]);
	}
}