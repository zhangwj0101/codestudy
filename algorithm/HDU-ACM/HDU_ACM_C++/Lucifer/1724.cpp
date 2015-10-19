////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-29 19:57:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1724
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
	double s1,s2,s;
	int a,b,l,r,t;
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&l,&r);
		s1=sqrt(1.0*a*a-r*r);
		s2=sqrt(1.0*a*a-l*l);
		s=b*(r*s1+atan(r/s1)*a*a-l*s2-atan(l/s2)*a*a)/a;
		printf("%.3lf\n",s);
	}
	return 0;
}