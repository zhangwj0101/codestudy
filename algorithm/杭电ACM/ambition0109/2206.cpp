////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-18 13:32:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2206
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int num,i,k;
	char str[101];
	while(gets(str))
	{
		for(i=0,num=0,k=0;str[i]!='\0';i++)
			if(str[i]<='9'&&str[i]>='0')
			{
				num=num*10+str[i]-'0';
				if(num>255||num<0)
					{k=0;break;}
			}
			else if(str[i]=='.'&&str[i+1]!='.'&&str[i+1]!='\0')
			{k++;num=0;}
			else
			{k=0;break;}
		if(k==3)
			printf("YES\n");
		else
			printf("NO\n");
	}
}