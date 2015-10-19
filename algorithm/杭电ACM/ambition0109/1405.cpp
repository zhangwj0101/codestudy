////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 16:15:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1405
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
bool prime[65536];
void main()
{
	int n,m,i,j,count,t,num;
	for(i=2;i<65536;i++)
		prime[i]=true;
	for(i=2;i<sqrt(65536.);i++)
	{
		if(prime[i])
		{
			for(j=i;j*i<65536;j++)
				prime[j*i]=false;
		}
	}
	t=1;
	while(scanf("%d",&n),n>0)
	{
		if(t!=1) printf("\n");
		num=n;printf("Case %d.\n",t++);
		for(i=2,count=0;;i++,count=0)
		{
			if(prime[i])
			{
				while(!(num%i))
				{
					count++;
					num/=i;
				}
				if(count!=0)
				{
					printf("%d %d",i,count);
					printf(" ");
					if(num==1){printf("\n");break;}
				}
			}
		}
	}
}