////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-01 14:48:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1161
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int i;
	char str[1001];
	while(gets(str)!=NULL)
	{
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]<='Z'&&str[i]>='A')
				str[i]+=32;
		}
		printf("%s\n",str);
	}
}