////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-25 14:18:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1062
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,t,j;
	char ch[1001];
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		gets(ch);
		for(i=0,t=0;ch[i]!='\0';i++)
		{
			if((ch[i]==' '))
			{
				for(j=i-1;j>=t;j--)
					printf("%c",ch[j]);
				printf(" ");
				t=i+1;
			}
		}
		for(j=i-1;j>=t;j--)
			printf("%c",ch[j]);
		printf("\n");
	}
}