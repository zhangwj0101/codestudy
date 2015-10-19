////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-09 17:53:35
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2043
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,x1,x2,x3,x4,count;
	char str[51];
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		gets(str);count=0;
		for(i=0;str[i]!='\0';i++);
		if(i<17&&i>7)
			for(i=0,x1=x2=x3=x4=1;str[i]!='\0';i++)
			{
				if((str[i]<='z')&&(str[i]>='a'))
				{
					if(x1)
					{x1=0;count++;}
				}
				else if((str[i]<='Z')&&(str[i]>='A'))
				{
					if(x2)
					{x2=0;count++;}
				}
				else if((str[i]<='9')&&(str[i]>='0'))
				{
					if(x3)
					{x3=0;count++;}
				}
				else if(x4)
				{x4=0;count++;}	
				if(count>=3)
					break;
			}
		if(count>=3)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
