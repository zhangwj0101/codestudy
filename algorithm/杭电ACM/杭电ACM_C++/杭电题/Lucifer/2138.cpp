////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-14 12:20:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
inline int prime(int n)
{
	int sl,i;
	sl=sqrt(1.0*n);
	for(i=2;i<=sl;i++)
		if(n%i==0)
			return 0;
	return 1;
} 
int main()
{
	int n,m,k,i;
	while(scanf("%d",&n)==1)
	{
		for(k=i=0;i<n;i++)
		{
			scanf("%d",&m);
			if(prime(m))k++;
		}
		printf("%d\n",k);
	}
	return 0;
}