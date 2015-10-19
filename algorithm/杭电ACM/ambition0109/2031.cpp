////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-10 18:52:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2031
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
main()
{
	int i,num,base;
	char str[1000];
	while(scanf("%d%d",&num,&base)!=EOF)
	{
		itoa(abs(num),str,base);
		if(num<0)
			printf("-");
		for(i=0;str[i]!='\0';i++)
			if(str[i]<='f'&&str[i]>='a')
				str[i]-=32;
		printf("%s\n",str);
	}
}