////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 17:47:46
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1321
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
void main()
{
	int n,i;
	char str[71];
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		gets(str);
		for(i=0;str[i]!='\0';i++);
		for(i-=1;i>=0;i--)printf("%c",str[i]);
		printf("\n");
	}
}