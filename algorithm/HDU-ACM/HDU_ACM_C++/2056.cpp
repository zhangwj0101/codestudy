////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-13 00:56:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2056
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;
#define MX(a,b) a>b?a:b
#define MN(a,b) a<b?a:b
int main()
{
	int i;
	double a[2],b[2];
	double x[4],y[4];
	while(scanf("%lf%lf",x,y)!=EOF)
	{
		for(i=1;i<4;i++)
			scanf("%lf%lf",x+i,y+i);
		if (x[0] > x[1]) swap(x[0], x[1]);
        if (y[0] > y[1]) swap(y[0], y[1]);
        if (x[2] > x[3]) swap(x[2], x[3]);
        if (y[2] > y[3]) swap(y[2], y[3]);
		a[0]=MX(x[0],x[2]);
		a[1]=MN(x[1],x[3]);
		b[0]=MX(y[0],y[2]);
		b[1]=MN(y[1],y[3]);
		printf("%.2f\n", (a[0]<a[1] && b[0]<b[1])? (b[1]-b[0])*(a[1]-a[0]) : 0);
	}
	return 0;
}