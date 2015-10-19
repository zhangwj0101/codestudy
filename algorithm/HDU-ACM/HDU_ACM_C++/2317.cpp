////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-23 15:12:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2317
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,r,e,c;
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d",&r,&e,&c);
		puts(e-c==r?"does not matter":(e-c>r?"advertise":"do not advertise"));
	}
	return 0;
}