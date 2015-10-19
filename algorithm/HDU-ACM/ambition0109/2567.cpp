////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-20 12:00:44
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2567
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,l;
	char str1[51],str2[51];
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		scanf("%s%s",&str1,&str2);
		for(i=0,l=0;str1[i]!='\0';i++)
			l++;
		for(i=0;i<l/2;i++)
			printf("%c",str1[i]);
		printf("%s",str2);
		for(;i<l;i++)
			printf("%c",str1[i]);
		printf("\n");
	}
}