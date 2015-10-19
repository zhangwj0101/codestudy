////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-01-08 15:35:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2551
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		i=sqrt(2*sqrt(1.0*n));
		if(i*(i+1)/2*i*(i+1)/2<n)i++;
		printf("%d\n",i);
	}
	return 0;
}