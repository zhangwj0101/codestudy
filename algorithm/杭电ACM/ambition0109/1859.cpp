////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-04 19:13:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1859
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,xy[2],min[2],max[2];
	while(scanf("%d%d",&min[0],&min[1]),min[0]||min[1])
	{
		max[0]=min[0],max[1]=min[1];
		while(scanf("%d%d",&xy[0],&xy[1]),xy[0]||xy[1])
		{
			if(xy[0]>max[0])
				max[0]=xy[0];
			else if(xy[0]<min[0])
				min[0]=xy[0];
			if(xy[1]>max[1])
				max[1]=xy[1];
			else if(xy[1]<min[1])
				min[1]=xy[1];
		}
		printf("%d %d %d %d\n",min[0],min[1],max[0],max[1]);
	}
}