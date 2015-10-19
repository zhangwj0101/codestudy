////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-13 13:44:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2503
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
	int n,a,b,c,d,t1,t2,t;
	cin>>n;
	while(n--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		t1=a*d+b*c;
		t2=b*d;
		t=gcd(t1,t2);
		printf("%d %d\n",t1/t,t2/t);
	}
   return 0;
}