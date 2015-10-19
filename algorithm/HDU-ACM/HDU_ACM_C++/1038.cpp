////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-26 08:34:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1038
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const double P=3.1415927;
const double M=63360;
const int H=3600;
int main()
{
	int i,r;
	double d,t;
	for(i=1;cin>>d>>r>>t&&r;i++)
	{
		d=d*P*r/M;
		t=d*H/t;
		printf("Trip #%d: %.2lf %.2lf\n",i,d,t);
	}
    return 0;
}