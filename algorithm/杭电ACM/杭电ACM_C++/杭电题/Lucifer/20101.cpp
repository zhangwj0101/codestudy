////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-01-19 19:44:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2010
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#define TRI(x) (x)*(x)*(x)
using namespace std;
int main()
{
	int m,n,k,i,j,out[900];
	while(scanf("%d%d",&m,&n)==2)
	{
		for(k=j=0,i=m;i<=n;i++)
			if(i==TRI(i/100)+TRI((i%100)/10)+TRI(i%10))
				out[j++]=i;
		if(j)
			for(i=0;i<j;i++)
				printf((i?" %d":"%d"),out[i]);
		else
			printf("no");
		puts("");
	}
	return 0;
}