////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-25 17:19:37
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1860
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int i,j,num[5];
	char str[6],ss[81];
	while(gets(str),str[0]!='#')
	{
		gets(ss);
		for(i=0;i<5;i++)
			num[i]=0;
		for(i=0;ss[i]!='\0';i++)
		{
			for(j=0;str[j]!='\0';j++)
				if(ss[i]==str[j])
					num[j]++;
		}
		for(i=0;str[i]!='\0';i++)
			printf("%c %d\n",str[i],num[i]);
	}
}