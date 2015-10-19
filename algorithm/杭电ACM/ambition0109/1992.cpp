////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-19 12:58:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1992
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#define MAXN 50
__int64 a[MAXN],b[MAXN],c[MAXN];

int main()
{
	__int64 n,i;
	int w;
	a[0]=a[1]=b[1]=c[1]=1;
	b[0]=c[0]=0;
	for(i=2;i<30;i++){
		a[i]=a[i-1]+a[i-2]+b[i-1]+2*c[i-1];
		b[i]=a[i-1]+b[i-2];
		c[i]=a[i-1]+c[i-1];
	}
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		printf("%I64d %I64d\n",i,a[w]);
	}
	return 0;
}