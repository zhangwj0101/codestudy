////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-29 20:21:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
/*
 * 1053.cpp
 *
 *  Created on: 2010-10-29
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(void)
{
	double a[200];
	char b[200],c[200];
	int C;
	scanf("%d",&C);
	while(C--)
	{
		int n,i;
		int k1,k2=0;
		scanf("%d",&n);
		for(i=0;i<105;i++)
			a[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",b);
			int lb=strlen(b);
			int j;
			bool flag;
			double sum=0;
			for(j=0;j<lb;j++)
			{
				k1=0;
				flag=0;
				while(j<lb&&b[j]!='-')
				{
					c[k1++]=b[j];
					j++;
					flag=1;
				}
				if(flag)
					sum+=atoi(c);
				for(int x=0;x<k1;x++)
					c[x]='\0';
			}
			if(sum!=0)
				a[k2++]=sum;
		}
		if(k2==0)
		{
			puts("0.00");
			continue;
		}
		double res=0;
		for(i=0;i<k2;i++)
		{
			res+=1/a[i];
		}
		printf("%.2lf\n",1.0/res);
	}
}
