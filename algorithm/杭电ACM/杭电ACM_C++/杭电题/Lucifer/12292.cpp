////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-02 20:48:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
void main()
{
	int a,b,k,i,ten;
	while (scanf("%d%d%d",&a,&b,&k),a||b)
	{
		ten=1;
		for (i=0;i<k;i++)
			ten*=10;
		printf("%d\n",((a-b)%ten)?a+b:-1);
	}
}