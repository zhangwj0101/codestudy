////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-13 13:25:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1969
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
#define pi 3.141592653589793
int r[10001];
double area[10001];
main()
{
	int n,m,i,count,o;
	double min,max,sum,half,temp;
	for(scanf("%d",&o);o>0;o--)
	{
		for(scanf("%d%d",&n,&m),sum=0,i=0;i<n;i++)
		{
			scanf("%d",&r[i]);
			area[i]=(double)(r[i]*r[i])*pi;
			sum+=area[i];
		}
		min=0;max=sum/(double)(m+1);
		half=(min+max)/2.;temp=max;
		while(fabs(half-temp)>0.0000001)
		{
			for(i=0,count=0;i<n;i++)
				count+=(int)(area[i]/half);
			temp=half;
			if(count>=m+1) min=half;
			else max=half;
			half=(min+max)/2;
		}
		printf("%.4lf\n",half);
	}
}