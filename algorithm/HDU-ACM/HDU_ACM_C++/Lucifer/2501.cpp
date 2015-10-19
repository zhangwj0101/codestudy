////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-13 14:50:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2501
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,a,b,c,i,m;
	cin>>n;
	while(n--)
	{
		a=b=c=1;
		scanf("%d",&m);
		for(i=2;i<=m;i++)
		{
			c=2*a+b;
			a=b;
			b=c;
		}
		printf("%d\n",c);
	}
	return 0;
}