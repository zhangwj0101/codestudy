////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-01-08 17:05:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2561
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,c,i,t,m1,m2;
	scanf("%d",&c);
	while (c--)
	{
		m1=m2=100000000;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			if(m1>t){m2=m1;m1=t;}
			else if(m2>t)m2=t;
		}
		printf("%d\n",m2);
	}
	return 0;
}