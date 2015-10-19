////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-13 21:37:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2080
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
//自己怎么都不过，
#include <math.h>
#include <stdio.h>
#define sqr(x) ((x)*(x))
int main(void)
{
	int n;
	double x[2], y[2];
	
	scanf("%d", &n);
	while (n-- && scanf("%lf%lf%lf%lf", x, y, x+1, y+1))
	{
		y[0] = asin(y[0]/sqrt(sqr(x[0])+sqr(y[0])))/acos(-1.0)*180;
		y[1] = asin(y[1]/sqrt(sqr(x[1])+sqr(y[1])))/acos(-1.0)*180;
		if (!y[0] && x[0] < 0) y[0] = 180;
		if (!y[1] && x[1] < 0) y[1] = 180;
		y[0] -= y[1];
		while (y[0] < 0) y[0] += 360;
		while (y[0] > 360) y[0] -= 360;
		while (y[0] > 180) y[0] = 360 - y[0];
		printf("%.2f\n", y[0]);
	}
	
	return 0;
}