////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-23 17:56:22
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2131
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int m,sum;
	char ch,str[201];
	while(scanf("%c %s",&ch,str)!=EOF)
	{
		getchar();
		if(ch<='Z'&&ch>='A') ch+=32;
		for(m=0,sum=0;str[sum]!='\0';sum++)
		{
			if(str[sum]<='Z'&&str[sum]>='A') str[sum]+=32;
			if(ch==str[sum])
				m++;
		}
		printf("%.5lf\n",(double)m/(double)sum);
	}
}