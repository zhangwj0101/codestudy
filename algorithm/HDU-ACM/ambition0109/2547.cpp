////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 13:20:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2547
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n;
	double x1,x2,y1,y2;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		printf("%.1lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	}
}