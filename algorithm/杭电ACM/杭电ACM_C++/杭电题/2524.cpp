////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-31 19:38:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2524
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",(n*n+n)*(m*m+m)/4);
	}
	return 0;
}