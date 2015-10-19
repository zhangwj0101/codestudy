////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-02 20:49:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
void main()
{
	int num[101];
	int n,i,score;
	while (scanf("%d",&n),n)
	{
		memset(num,0,sizeof(num));
		for (i=0;i<n;i++)
		{
			scanf("%d",&score);
			num[score]++;
		}
		scanf("%d",&score);
		printf("%d\n",num[score]);
	}
}