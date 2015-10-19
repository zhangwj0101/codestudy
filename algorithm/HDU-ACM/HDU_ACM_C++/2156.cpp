////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-16 21:25:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2156
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,i;
	double s;
	while(scanf("%d",&n)&&n)
	{
		s=n;
		for(i=2;--n;i++)
			s+=2.0*n/i;
		printf("%.2lf\n",s);
	}
	return 0;
}