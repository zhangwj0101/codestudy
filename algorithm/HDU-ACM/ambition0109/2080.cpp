////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-15 19:15:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2080
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
#define PI 3.1415926
main()
{
	int n,i;
	double x1,x2,y1,y2,angle1,angle2,angle;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		angle1=atan2(y1,x1)/PI*180;
		angle2=atan2(y2,x2)/PI*180;
		angle=fabs(angle1-angle2);
		if(angle>180)
			angle=360-angle;
		printf("%.2lf\n",angle);
	}
}