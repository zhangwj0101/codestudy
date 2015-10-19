////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 15:16:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2178
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	while(n--)
	{
		scanf("%d",&m);
		printf("%d\n",(1<<m)-1);
	}
	return 0;
}