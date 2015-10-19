////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-08 21:33:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1046
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
//旅行商问题 ， 要求回到原点的最小步数
//对乘积分奇偶考虑 
#include <cstdio>
using namespace std;
int main()
{
	int i,t,n,x,y;
	
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Scenario #%d:\n",i);
		scanf("%d %d",&x,&y);
		n=x*y;
		if(n%2==0)
			printf("%d.00\n",n);
		else
			printf("%d.41\n",n);
		printf("\n");
	}
	return 0;
}