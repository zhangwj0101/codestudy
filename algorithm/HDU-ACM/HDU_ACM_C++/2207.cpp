////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 10:52:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2207
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
union 
{
	unsigned long ip;
	unsigned char sub[4];
}IP;
int main()
{
	int n,i;
	while(scanf("%d",&n)==1)
	{
		n+=3;
		IP.ip=0xFFFFFFFF;
		i=1;
		while(i<n)i<<=1;
		IP.ip-=(i-1);
		for(i=3;i>=0;i--)
			printf("%d%c",IP.sub[i],i?'.':'\n');
	}
   return 0;
}