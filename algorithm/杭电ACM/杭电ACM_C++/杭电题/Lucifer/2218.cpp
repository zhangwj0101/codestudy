////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 09:26:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2218
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,i,s,a;
	cin>>n;
	while(n--)
	{
		for(s=i=0;i<6;i++)
		{
			scanf("%d",&a);
			s+=(i%2?-a:a);
		}
		puts(!s?"YES":"NO");
	}
   return 0;
}