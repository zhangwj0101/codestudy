////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-10 12:24:30
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1332
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j;
	char num[9];
	while(scanf("%d%s",&n,num),n||(num[0]=='0'&&num[0]=='\0'))
	{
		for(i=0;num[i]!='\0';i++)
		{
			if(i)
				printf(" ");
			if(num[i]=='0'||num[i]=='2'||num[i]=='3'||num[i]=='5'||num[i]=='6'||num[i]=='7'||num[i]=='8'||num[i]=='9')
			{
				printf(" ");
				for(j=0;j<n;j++)
					printf("-");
				printf(" ");
			}
			else
				for(j=0;j<n+2;j++)
					printf(" ");
		}
		printf("\n");
		for(m=0;m<n;m++)
		{
			for(i=0;num[i]!='\0';i++)
			{
				if(i)
					printf(" ");
				if(num[i]=='0'||num[i]=='4'||num[i]=='5'||num[i]=='6'||num[i]=='8'||num[i]=='9')
					printf("|");
				else
					printf(" ");
				for(j=0;j<n;j++)
					printf(" ");
				if(num[i]=='0'||num[i]=='1'||num[i]=='2'||num[i]=='3'||num[i]=='4'||num[i]=='7'||num[i]=='8'||num[i]=='9')
					printf("|");
				else
					printf(" ");
			}
			printf("\n");
		}
		for(i=0;num[i]!='\0';i++)
		{
			if(i)
				printf(" ");
			if(num[i]=='2'||num[i]=='3'||num[i]=='4'||num[i]=='5'||num[i]=='6'||num[i]=='8'||num[i]=='9')
			{
				printf(" ");
				for(j=0;j<n;j++)
					printf("-");
				printf(" ");
			}
			else
				for(j=0;j<n+2;j++)
					printf(" ");
		}
		printf("\n");
		for(m=0;m<n;m++)
		{
			for(i=0;num[i]!='\0';i++)
			{
				if(i)
					printf(" ");
				if(num[i]=='0'||num[i]=='2'||num[i]=='6'||num[i]=='8')
					printf("|");
				else
					printf(" ");
				for(j=0;j<n;j++)
					printf(" ");
				if(num[i]=='0'||num[i]=='1'||num[i]=='3'||num[i]=='4'||num[i]=='5'||num[i]=='6'||num[i]=='7'||num[i]=='8'||num[i]=='9')
					printf("|");
				else
					printf(" ");
			}
			printf("\n");
		}
		for(i=0;num[i]!='\0';i++)
		{
			if(i)
				printf(" ");
			if(num[i]=='0'||num[i]=='2'||num[i]=='3'||num[i]=='5'||num[i]=='6'||num[i]=='8'||num[i]=='9')
			{
				printf(" ");
				for(j=0;j<n;j++)
					printf("-");
				printf(" ");
			}
			else
				for(j=0;j<n+2;j++)
					printf(" ");
		}
		printf("\n\n");
	}
}