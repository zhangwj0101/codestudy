////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-02-06 11:03:58
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2265
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
void main()
{
	char str[200];
	int len,i,j;
	while (gets(str))
	{
		len=strlen(str);
		for (i=j=0;i<len;i++)
		{
			if (str[i]!=' ')
			{
				str[j]=str[i];
				j++;
			}
		}
		str[j]=0;
		for (i=2;i<j;i+=3)
			putchar(str[i]),str[i]=0;
		for(i=1;i<j;i+=2)
		{
			if (str[i]!=0)
				putchar(str[i]),str[i]=0;
		}
		for (i=0;i<j;i++)
		{if (str[i]!=0)
			putchar(str[i]);}
		puts("");
	}
}