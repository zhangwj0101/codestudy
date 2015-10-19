////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-26 19:45:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1209
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;

double getclock(int hh,int mm)
{
	double H,M;if(hh>=12) hh-=12;
	H=((double)hh+(double)mm/60.)/12.*360.;
	M=(double)mm/60.*360.;
	return (fabs(H-M)>180.?(360.-fabs(H-M)):fabs(H-M));
}
void main()
{
	int n,i,j;
	int hour,minus,cclock[5];
	double clock[5];
	for(scanf("%d",&n);n;n--)
	{
		for(i=0;i<5;i++)
		{
			scanf("%d:%d",&hour,&minus);
			cclock[i]=hour*100+minus;
			clock[i]=getclock(hour,minus);
		}
		for(i=0;i<5;i++)
			for(j=i+1;j<5;j++)
			{
				if(clock[i]>clock[j])
				{
					double t=clock[j];clock[j]=clock[i];clock[i]=t;
					cclock[i]^=cclock[j];cclock[j]^=cclock[i];cclock[i]^=cclock[j];
				}
				else if(clock[i]==clock[j])
				{
					if (cclock[i]>cclock[j])
					{
						double t=clock[j];clock[j]=clock[i];clock[i]=t;
						cclock[i]^=cclock[j];cclock[j]^=cclock[i];cclock[i]^=cclock[j];
					}
				}
			}
		printf("%02d:%02d\n",cclock[2]/100,cclock[2]%100);
	}
}
