////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 15:49:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2162
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,m,s,c=0;
	while(scanf("%d",&n)&&n>0)
	{
		s=0;
		while(n--)
		{
			scanf("%d",&m);
			s+=m;
		}
		printf("Sum of #%d is %d\n",++c,s);
	}
	return 0;
}