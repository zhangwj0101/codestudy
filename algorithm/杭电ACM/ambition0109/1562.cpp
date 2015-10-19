////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-11 17:57:56
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1562
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,a,b,c,num;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(num=1000,i=1;num<10000;num++)
		{
			if((num%a==0)&&(num%b==(b-1))&&(num%c==(c-2)))
			{printf("%d\n",num);i=0;break;}
		}
		if(i)
			printf("Impossible\n");
	}
}