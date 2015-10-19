////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-05 10:53:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1850
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num[100];
char two[100][25],anst[25];
main()
{
	int m,i,ans,t,count;
	while(scanf("%d",&m),m)
	{
		for(count=0,i=0,ans=0;i<m;i++)
		{
			scanf("%d",&num[i]);
			itoa(num[i],two[i],2);
			ans=ans^num[i];
		}
		if(ans)
		{
			itoa(ans,anst,2);
			t=strlen(anst);
			for(i=0;i<m;i++)
			{
				if(strlen(two[i])>=t)
					if(two[i][strlen(two[i])-t]=='1')
						count++;
			}
			printf("%d\n",count);
		}
		else printf("0\n");
	}
}