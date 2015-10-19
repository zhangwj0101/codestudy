////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-21 12:27:20
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2056
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	double x[4],y[4],xx,yy,tmp,ans;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])!=EOF)
	{
		if(x[0]>x[1])
			tmp=x[0],x[0]=x[1],x[1]=tmp;
		if(y[0]>y[1])
			tmp=y[0],y[0]=y[1],y[1]=tmp;
		if(x[2]>x[3])
			tmp=x[2],x[2]=x[3],x[3]=tmp;
		if(y[2]>y[3])
			tmp=y[2],y[2]=y[3],y[3]=tmp;
		if(((x[2]>=x[1])||(y[2]>=y[1]))||((x[3]<=x[0])||(y[3]<=y[0])))
			ans=0;
		else
		{
			xx=fabs((x[0]>x[2]?x[0]:x[2])-(x[3]>x[1]?x[1]:x[3]));
			yy=fabs((y[0]>y[2]?y[0]:y[2])-(y[3]>y[1]?y[1]:y[3]));
			ans=xx*yy;
		}
		printf("%.2lf\n",ans);
	}
}