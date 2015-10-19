////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-15 21:19:39
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,num[100],time;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(i=1,time=num[0]*6;i<n;i++)
		{
			if(num[i]-num[i-1]>0)
				time+=(num[i]-num[i-1])*6;
			else
				time+=(num[i-1]-num[i])*4;
		}
		time+=5*n;
		printf("%d\n",time);
	}
}