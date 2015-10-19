////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-14 14:15:42
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1086
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,t,count;
	double x[100][2],y[100][2],a,b;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
		for(i=0,count=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				t=1;
				a=(x[i][1]-x[i][0])*(y[j][0]-y[i][0])-(y[i][1]-y[i][0])*(x[j][0]-x[i][0]);
				b=(x[i][1]-x[i][0])*(y[j][1]-y[i][0])-(y[i][1]-y[i][0])*(x[j][1]-x[i][0]);
				if(a*b>0)
					t=0;
				else if(a==0&&b!=0)
				{
					if(x[j][0]<=(x[i][1]>x[i][0]?x[i][1]:x[i][0])&&x[j][0]>=(x[i][1]<x[i][0]?x[i][1]:x[i][0])&&y[j][0]<=(y[i][1]>y[i][0]?y[i][1]:y[i][0])&&y[j][0]>=(y[i][1]<y[i][0]?y[i][1]:y[i][0]))
						t=2;
				}
				else if(a!=0&&b==0)
				{
					if(x[j][1]<=(x[i][1]>x[i][0]?x[i][1]:x[i][1])&&x[j][0]>=(x[i][1]<x[i][0]?x[i][1]:x[i][0])&&y[j][1]<=(y[i][1]>y[i][0]?y[i][1]:y[i][0])&&y[j][1]>=(y[i][1]<y[i][0]?y[i][1]:y[i][0]))
						t=2;
				}
				if(t==1)
				{
					a=(x[j][1]-x[j][0])*(y[i][0]-y[j][0])-(y[j][1]-y[j][0])*(x[i][0]-x[j][0]);
					b=(x[j][1]-x[j][0])*(y[i][1]-y[j][0])-(y[j][1]-y[j][0])*(x[i][1]-x[j][0]);
					if(a*b>0)
						t=0;
					else if(a==0&&b!=0)
					{
						if(x[i][0]<=(x[j][1]>x[j][0]?x[j][1]:x[j][0])&&x[i][0]>=(x[j][1]<x[j][0]?x[j][1]:x[j][0])&&y[i][0]<=(y[j][1]>y[j][0]?y[j][1]:y[j][0])&&y[i][0]>=(y[j][1]<y[j][0]?y[j][1]:y[j][0]))
							t=2;
					}
					else if(a!=0&&b==0)
					{
						if(x[i][1]<=(x[j][1]>x[j][0]?x[j][1]:x[j][1])&&x[i][0]>=(x[j][1]<x[j][0]?x[j][1]:x[j][0])&&y[i][1]<=(y[j][1]>y[j][0]?y[j][1]:y[j][0])&&y[i][1]>=(y[j][1]<y[j][0]?y[j][1]:y[j][0]))
							t=2;
					}
				}
				if(t)
					count++;				
			}
			printf("%d\n",count);
	}
}