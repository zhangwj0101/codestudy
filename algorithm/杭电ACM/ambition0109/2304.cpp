////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-26 19:53:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2304
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

void main()
{
	int n,m,sum,t,i;
	for(scanf("%d",&n);n;n--)
	{
		for(scanf("%d",&m),sum=0,i=0;i<m;i++)
		{
			scanf("%d",&t);
			sum+=t;
		}
		printf("%d\n",sum+1-m);
	}
}