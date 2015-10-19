////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-20 21:47:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1085
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[8001];
main()
{
	int a,b,c,i,j,k;
	while(scanf("%d%d%d",&a,&b,&c),a||b||c)
	{
		for(i=0;i<=8000;i++)
			num[i]=0;
		for(i=0;i<=a;i++)
			num[i]=1;
		for(i=0;i<=a;i++)
			for(j=0,k=0;k<=b;j+=2,k++)
				num[j+i]+=num[i];
		for(i=0;i<=a+2*b;i++)
			for(j=0,k=0;k<=c;j+=5,k++)
				num[j+i]+=num[i];
		i=0;
		while(num[i])i++;
		printf("%d\n",i);
	}
}