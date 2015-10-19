////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-05 14:06:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,max,min;
	float score[100],ans;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%f",&score[0]);
		scanf("%f",&score[1]);
		max=score[0]>score[1]?0:1;
		min=score[0]<=score[1]?0:1;
		for(i=2;i<n;i++)
		{
			scanf("%f",&score[i]);
			if(score[i]>score[max])
				max=i;
			else if(score[i]<score[min])
				min=i;
		}
		for(i=0,ans=0;i<n;i++)
			if(i!=max&&i!=min)
				ans+=score[i];
		printf("%.2f\n",ans/(n-2));
	}
}