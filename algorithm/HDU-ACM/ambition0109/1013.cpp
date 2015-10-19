////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-10 12:47:10
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int i,m;
	char num[1001];
	while(scanf("%s",num),num[0]!='0'||num[1]!='\0')
	{
		for(i=0;num[i+1]!='\0';i++)
		{
			m=num[i]+num[i+1]-'0'*2;
			m=m/10+m%10;
			num[i+1]=m+'0';
		}
		printf("%c\n",num[i]);
	}
}