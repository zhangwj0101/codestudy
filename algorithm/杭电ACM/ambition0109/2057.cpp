////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-09 19:08:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2057
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main()
{
	long long a,b;
	while(scanf("%I64X%I64X",&a,&b)!=EOF)
	{
		if(a+b>=0) printf("%I64X\n",a+b);
		else printf("-%I64X\n",-(a+b));
	}
}