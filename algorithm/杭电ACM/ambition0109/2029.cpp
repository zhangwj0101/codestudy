////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-08 11:30:58
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2029
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,l,x;
	char str[101];
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		gets(str);
		for(l=0;str[l]!='\0';l++) ;
		l--;
		for(i=0,x=1;i<l-i;i++)
			if(str[i]!=str[l-i])
			{x=0;break;}
		if(x)
			printf("yes\n");
		else
			printf("no\n");
	}
}