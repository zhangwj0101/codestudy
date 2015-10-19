////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-17 11:13:01
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	int score[101],sc,line;
	while (scanf("%d",&n),n)
	{
		memset(score,0,sizeof(score));
		while (n--)
		{
			scanf("%d",&sc);
			score[sc]++;
		}
		scanf("%d",&line);
		printf("%d\n",score[line]);
	}
	return 0;
}