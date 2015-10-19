////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-25 13:43:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1996
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int i,n,tt;
	__int64 a[30],t;
	for(t=1,i=0;i<30;i++,t*=3)
		a[i]=t;
	cin>>tt;
	while(tt--)
	{
		scanf("%d",&n);
		printf("%I64d\n",a[n]);
	}
	return 0;
}