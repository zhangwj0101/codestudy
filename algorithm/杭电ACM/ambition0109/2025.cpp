////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-06 11:53:46
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2025
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	char str[101],max;
	int i;
	while(scanf("%s",str)!=EOF)
	{
		for(max=*str,i=1;*(str+i)!='\0';i++)
			if(*(str+i)>max)
				max=*(str+i);
		for(i=0;*(str+i)!='\0';i++)
		{
			printf("%c",*(str+i));
			if(*(str+i)==max)
				printf("\(max\)");
		}
		printf("\n");
	}
}