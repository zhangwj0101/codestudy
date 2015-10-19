////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-15 16:51:24
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j;
	char str[201],*p;
	while(scanf("%d",&n),n)
	{
		scanf("%s",str);
		for(i=0;str[i]!='\0';i++);
			m=i;p=str;
		for(i=0;i<n;i++)
			for(j=0;j<m/n;j++)
			{
				if(j%2)
					printf("%c",*(p+n*(j+1)-i-1));
				else
					printf("%c",*(p+n*j+i));
			}
		printf("\n");
	}
}