////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-14 11:25:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2134
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	double sq3=sqrt(3.0);
	double sq2=sqrt(2.0);
	while(scanf("%d",&n),n)
		printf("%.3lf %.3lf\n",n/sq3,n*sq2/sq3);
	return 0;
}