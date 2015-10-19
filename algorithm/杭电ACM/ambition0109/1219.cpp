////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-01 18:02:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1219
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<stdio.h>
char str[100000];
main()
{
	int i;
	int num[26];
	while(gets(str))
	{
		for(i=0;i<26;i++)
			num[i]=0;
		for(i=0;str[i]!='\0';i++)
			if(str[i]<='z'&&str[i]>='a')
				num[str[i]-'a']+=1;
		for(i=0;i<26;i++)
			printf("%c:%d\n",i+'a',num[i]);
		printf("\n");
	}
}