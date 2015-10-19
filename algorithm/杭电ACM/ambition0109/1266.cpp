////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 17:57:55
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1266
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	int n,num,i,j;
	char str[20],t;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&num);
		itoa(abs(num),str,10);
		for(i=0;str[i]!='\0';i++);
		for(i-=1;str[i]=='0';i--);
		for(j=0;j<i;j++,i--)
		{t=str[j];str[j]=str[i];str[i]=t;}
		if(num<0) printf("-");
		puts(str);
	}
}