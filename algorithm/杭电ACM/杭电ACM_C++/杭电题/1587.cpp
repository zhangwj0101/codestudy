////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 21:35:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1587
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,m,n,a,min;
	while(scanf("%d%d",&n,&m)==2)
	{
		for(min=10000,i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a<min)min=a;
		}
		printf("%d\n",m/min);
	}
   return 0;
}