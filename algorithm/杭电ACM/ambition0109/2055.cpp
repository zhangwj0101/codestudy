////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-10 19:39:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2055
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,a,b;
	char ch;
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		scanf("%c%d",&ch,&b);getchar();
		if(ch>='a'&&ch<='z')
			a=0-(ch-96);
		else if(ch>='A'&&ch<='Z')
			a=ch-64;
		printf("%d\n",a+b);
	}
}