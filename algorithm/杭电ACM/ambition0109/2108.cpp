////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-13 21:07:24
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,t,x[102],y[102];
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&x[i],&y[i]);
		x[i]=x[0];y[i]=y[0];x[i+1]=x[1];y[i+1]=y[1];
		for(i=0,t=1;i<n;i++)
			if((x[i+1]-x[i])*(y[i+2]-y[i])-(x[i+2]-x[i])*(y[i+1]-y[i])<0)
			{t=0;break;}
		if(t)
			printf("convex\n");
		else
			printf("concave\n");
	}
}