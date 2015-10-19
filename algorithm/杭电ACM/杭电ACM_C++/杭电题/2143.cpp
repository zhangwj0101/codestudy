////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 12:28:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2143
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#define M {f=1;goto next;}
using namespace std;
int main()
{
	double a[3];
	int f,i,j,k;
	while(scanf("%lf%lf%lf",a,a+1,a+2)==3)
	{
		f=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				for(k=0;k<3;k++)
				{
					if(i!=j&&j!=k&&k!=i)
					{
						if((int)a[j]!=0)
						{
							if(a[i]/a[j]==a[k])M
							if((int)a[i]%(int)a[j]==(int)a[k])M
						}
						if(a[i]*a[j]==a[k])M
						if(a[i]+a[j]==a[k])M
						if(a[i]-a[j]==a[k])M
					}
				}
			}
		}
next:
		puts(f?"oh,lucky!":"what a pity!");
	}
	return 0;
}