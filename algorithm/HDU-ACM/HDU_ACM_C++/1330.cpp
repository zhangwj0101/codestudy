////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-28 14:50:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1330
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:672KB
//////////////////System Comment End//////////////////
#include <stdio.h>
double over[100000],sum=0;
int main()
{
	int i;
	
	for (i=1;i<100000;i++)
	{
		sum+=1.000000/(2*i);
		over[i]=sum;
	}
	printf("# Cards  Overhang\n");
	while(scanf("%d",&i)!=EOF)
		printf("%5d%10.3f\n",i,over[i]);
	return 0;
}