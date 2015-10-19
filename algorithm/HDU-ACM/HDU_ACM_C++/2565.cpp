////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-01-08 17:45:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2565
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define PS printf(" ")
#define PX printf("X")
#define PL puts("");
int main()
{
	int t,i,j,n;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for(i=0;i<n/2;i++)
		{
			for (j=0;j<i;j++)PS;PX;
			for (j=0;j<(n-2*i-2);j++)PS;PX;PL;
		}
		for (j=0;j<i;j++)PS;PX;PL;
		for(i=0;i<n/2;i++)
		{
			for (j=0;j<n/2-i-1;j++)PS;PX;
			for (j=0;j<1+2*i;j++)PS;PX;PL;
		}
		PL;
	}
	return 0;
}