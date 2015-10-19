////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-12-10 17:58:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2547
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
#define SQ(x) (x)*(x)
int main()
{
	double a,b,c,d;
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		printf("%.1lf\n",sqrt(SQ(a-c)+SQ(b-d)));
	}
	return 0;
}