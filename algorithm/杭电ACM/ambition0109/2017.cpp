////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-05 15:13:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2017
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,count;
	char ch;
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		ch='*';
		for(count=0;ch!='\n';)
		{
			scanf("%c",&ch);
			if(ch<='9'&&ch>='0')
				count++;
		}
		printf("%d\n",count);
	}
}