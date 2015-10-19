////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-12 19:30:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2520
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,num,i,s,v;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&num);
		for(i=0,s=0,v=1;i<num;i++,v+=2)
			if((s+=v)>=10000)
				s=s%10000;
		printf("%d\n",s);
	}
}