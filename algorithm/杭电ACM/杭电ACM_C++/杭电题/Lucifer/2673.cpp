////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-03-14 00:04:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2673
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[10001],n,i;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		for(i=0;i<n/2;i++)
		{
			printf(i?" ":"");
			printf("%d %d",a[n-i-1],a[i]);
		}
		if(2*i!=n)
			printf(" %d",a[i]);
		puts("");
	}
	return 0;
}