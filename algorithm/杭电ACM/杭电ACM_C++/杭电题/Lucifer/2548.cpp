////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-01-08 14:31:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2548
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t;
	double u,v,w,l;
	cin>>t;
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&u,&v,&w,&l);
		printf("%.3lf\n",l*w/(u+v));
	}
	return 0;
}