////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-27 17:10:30
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3356
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
#define pi 3.141
double dis[2][1000];
int main(void)
{
	int n,m,i,j,min,o=1;
	double xo[2],yo[2],x,y,s,r[2];
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		scanf("%lf%lf%lf%lf%lf",&xo[0],&yo[0],&xo[1],&yo[1],&s);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&x,&y);
			dis[0][i]=sqrt((xo[0]-x)*(xo[0]-x)+(yo[0]-y)*(yo[0]-y));
			dis[1][i]=sqrt((xo[1]-x)*(xo[1]-x)+(yo[1]-y)*(yo[1]-y));
		}
		for(min=n,i=0;i<n;i++)
		{
			if(dis[0][i]*dis[0][i]*pi<=s)
			{
				r[0]=dis[0][i];
				r[1]=sqrt((s-pi*r[0]*r[0])/pi);
				for(j=0,m=0;j<n;j++)
					if(r[0]<dis[0][j]&&r[1]<dis[1][j])
						m++;
				if(m<min)
					min=m;
			}
			if(dis[1][i]*dis[1][i]*pi<=s)
			{
				r[1]=dis[1][i];
				r[0]=sqrt((s-pi*r[1]*r[1])/pi);
				for(j=0,m=0;j<n;j++)
					if(r[1]<dis[1][j]&&r[0]<dis[0][j])
						m++;
				if(m<min)
					min=m;
			}
		}
		printf("%d. %d\n",o++,min);
	}
	return 0;
}