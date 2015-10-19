////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-01 14:50:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2151
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int a[101],b[101],n,p,m,t,i,k;
	while(scanf("%d%d%d%d",&n,&p,&m,&t)==4)
	{
		memset(a,0,4*n+8);
		a[p]=1;
		for(k=0;k<m;k++)
		{
			for(i=1;i<=n;i++)
				b[i]=a[i-1]+a[i+1];
			for(i=1;i<=n;i++)
				a[i]=b[i];
		}
		printf("%d\n",a[t]);
	}
	return 0;
}