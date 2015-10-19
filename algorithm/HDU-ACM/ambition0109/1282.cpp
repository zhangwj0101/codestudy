////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-23 20:47:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1282
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
main()
{
	int m,i,j,num[100],t;
	char str1[15],str2[15];
	while(scanf("%d",&num[0])!=EOF)
	{
		m=0;
		while(1)
		{
			itoa(num[m],str1,10);
			for(i=0;str1[i]!='\0';i++);
			for(j=0;i>0;j++,i--)
				str2[j]=str1[i-1];
			str2[j]='\0';
			for(i=0,t=1;i<j/2;i++)
				if(str1[i]!=str2[i])
				{t=0;m++;break;}
			if(t)
				break;
			num[m]=atoi(str2)+num[m-1];
		}
		printf("%d\n%d",m,num[0]);
		for(i=1;i<=m;i++)
			printf("--->%d",num[i]);
		printf("\n");
	}
}