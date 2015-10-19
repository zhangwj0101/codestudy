////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 11:29:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2104
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	int c=a%b;
	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int main()
{
	int m,n;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n<0)break;
		puts(gcd(n,m)!=1?"POOR Haha":"YES");
	}
	return 0;
}