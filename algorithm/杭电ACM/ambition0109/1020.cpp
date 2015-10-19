////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-16 19:18:37
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
main()
{
	int n,i,j=1;
	char a[10000],b;
	scanf("%d",&n);
	while(n!=0)
	{
		n--;
		scanf("%s",a);
		strcat(a,"#");
		for(i=1,b=a[0];a[i]!='\0';i++)
		{
			if(b==a[i])
				j+=1;
			if(b!=a[i])
			{
				if(j!=1)
					printf("%d",j);
				j=1;
				b=a[i];
				printf("%c",a[i-1]);
			}
		}
		printf("\n");
	}
}