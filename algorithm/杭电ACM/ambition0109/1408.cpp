////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 16:42:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1408
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j,k,time;
	double v,d;
	while(scanf("%lf%lf",&v,&d)!=EOF)
	{
		for(i=1,time=0;;i++)
		{
			for(j=0;j<i;j++)
			{
				v-=d;time++;
				if(v<=0) break;
			}
			if(v<=0) break;
			time++;
		}
		printf("%d\n",time);
	}
}