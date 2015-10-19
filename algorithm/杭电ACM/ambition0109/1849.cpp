////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-05 11:50:58
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1849
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num;
main()
{
	int m,i,ans;
	while(scanf("%d",&m),m)
	{
		for(i=0,ans=0;i<m;i++)
		{
			scanf("%d",&num);
			ans=ans^num;
		}
		if(ans)	printf("Rabbit Win!\n");
		else printf("Grass Win!\n");
	}
}