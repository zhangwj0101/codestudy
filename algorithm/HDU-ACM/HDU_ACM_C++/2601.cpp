////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-03-28 11:40:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2601
////Problem Title: 
////Run result: Accept
////Run time:1531MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	__int64 a;
	int i,j,k,sq,t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		scanf("%I64d",&a);
		a++;
		sq=sqrt(1.0*a);
		for(k=0,j=2;j<=sq;j++)
			if(a%j==0)
				k++;
		printf("%d\n",k);
	}
	return 0;
}