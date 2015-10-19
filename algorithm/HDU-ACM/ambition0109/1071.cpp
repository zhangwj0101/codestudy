////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-27 17:29:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1071
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

void main()
{
	int t;
	double x1, y1, x2, y2, x3, y3, m, n, a, b, c, p, q, area;
	for(scanf("%d",&t);t;t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
		m=(y2-y3)/(x2-x3);
		n=y2-m*x2;
		a=(x1*y3-x1*y2+x2*y1-x2*y3+x3*y2-x3*y1)/((x2-x1)*(x3-x1)*(x2-x3));
		b=(y2-y1)/(x2-x1)-a*(x2+x1);
		c=y1-a*x1*x1-b*x1;
		p=x2>x3?x3:x2;
		q=x2>x3?x2:x3;
		area=a/3.0*(q*q*q-p*p*p)+(b-m)/2.0*(q*q-p*p)+(c-n)*(q-p);
		printf("%.2f\n",area);
	}
}