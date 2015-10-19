////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-04 22:28:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1178
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int e,n;
	double s;
	while(scanf("%d",&n),n)
	{
		s=(double)n*(n+1)*(n+2)/6;
		e=(int)log10(s);
		s/=pow(10.0,e);
		printf("%.2lfE%d\n",s,e);
	}
   return 0;
}