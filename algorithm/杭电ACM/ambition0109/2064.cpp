////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-10 14:04:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>

void main()
{
	int n;
	__int64 num[36];
	num[0]=1;
	for(int i=1;i<36;i++)
		num[i]=num[i-1]*3;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%I64d\n",num[n]-1);
	}
}