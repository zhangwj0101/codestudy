////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-08-03 16:28:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1071
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
struct Point{double x,y;}p[4];
int main()
{
	double s;
	int i,n;
	cin>>n;
	while(n--)
	{
		for(i=1;i<=3;i++)
			cin>>p[i].x>>p[i].y;
		p[1].x-=p[2].x;
		p[1].y-=p[2].y;
		p[3].x-=p[2].x;
		p[3].y-=p[2].y;
		s=pow(p[3].x,2.0)*p[1].y/p[1].x-p[1].y*pow(p[3].x,3.0)/3.0/pow(p[1].x,2.0)-p[3].x*p[3].y/2;
		printf("%.2lf\n",s);
	}
   return 0;
}