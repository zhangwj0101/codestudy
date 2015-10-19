////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-14 09:23:47
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3346
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	char str[1000];
	int n,sum,i,num,square;
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		scanf("%s",&str);
		for(sum=0,i=0,num=0,square=0;str[i]!='\0';i++)
		{
			num=num*10;
			sum+=str[i]-'0';
			num+=str[i]-'0';
			square+=(str[i]-'0')*(str[i]-'0');
		}
		if(num%8&&sum%8&&square%8)
			printf("What a pity!\n");
		else
			printf("Lucky number!\n");
	}
}