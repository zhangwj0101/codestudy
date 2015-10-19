////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-08 11:41:21
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2030
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,count;
	char str[1000];
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		gets(str);
		for(count=0,i=0;str[i]!='\0';i++)
			if(str[i]&128)
				count++;
		printf("%d\n",count/2);
	}
}