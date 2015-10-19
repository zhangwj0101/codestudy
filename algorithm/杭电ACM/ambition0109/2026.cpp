////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-08 11:06:43
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2026
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int i;
	char str[101];
	while(gets(str))
	{
		if(str[0]<='z'&&str[0]>='a')
			str[0]-=32;
		for(i=0;str[i]!='\0';i++)
			if(str[i]==' ')
				if(str[i+1]<='z'&&str[i+1]>='a')
					str[i+1]-=32;
		puts(str);
	}
}