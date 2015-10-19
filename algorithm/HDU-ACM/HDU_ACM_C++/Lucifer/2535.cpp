////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-01-08 19:27:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2535
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
	int n,a[102],i,s;
	while (scanf("%d",&n),n)
	{
		for (i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		for(s=i=0;i<n/2+1;i++)
			s+=a[i]/2+1;
		printf("%d\n",s);
	}
	return 0;
}