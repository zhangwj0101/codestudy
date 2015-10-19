////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 20:09:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1527
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
double a = (1.0 + sqrt(5.0)) / 2.0;
double b  = (3.0 + sqrt(5.0)) / 2.0;
int main()
{
	int big, small, n, t1, t2,t;
	while(scanf("%d %d",&big,&small)==2)
	{
		if(big < small)
		{
			t=big;
			big=small;
			small=t;
		}
		n = ceil(big / b);
		t1 = a * n;
		t2 = b * n;
		if(small == t1 && big == t2)
			puts("0");
		else puts("1");
	}
	return 0;
}