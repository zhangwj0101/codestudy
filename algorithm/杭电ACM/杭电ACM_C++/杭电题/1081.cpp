////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-04 14:23:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1081
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int a[101][101]={0},i,n,max,j,e,sum,k;
	while(scanf("%d",&n)==1)
	{
		max=-128;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&e);
				a[i][j]=e+a[i][j-1];
			}
		for(i=0;i<=n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(sum=0,k=1;k<=n;k++)
				{
					sum=(sum>0?sum:0)+a[k][j]-a[k][i];
					if(max<sum)
						max=sum;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}