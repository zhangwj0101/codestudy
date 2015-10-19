////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 21:23:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1877
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	unsigned int a,b,m,temp;
	int c[40];
	int i;
	while(scanf("%d",&m),m)
	{
		scanf("%d%d",&a,&b);
		temp=a+b;
		if(!temp)
		{
			puts("0");
			continue;
		}
		for(i=0;temp;i++)
		{
			c[i]=temp%m;
			temp/=m;
		}
		while(i--)
		{
			printf("%d",c[i]);
		}
		puts("");
	}
	return 0;
}