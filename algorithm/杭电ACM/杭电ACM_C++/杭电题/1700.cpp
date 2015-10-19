////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-04 15:44:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1700
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include <cmath>
#define eps 5e-4
#define zero(x) (((x)>0?(x):-(x))<eps)
#define angle atan2(0.0,-1.0)*2/3
using namespace std;
struct point{double x,y;};
point rotate(point v){
	point ret;
	ret.x=v.x*cos(angle)-v.y*sin(angle);
	ret.y=v.x*sin(angle)+v.y*cos(angle);
	return ret;
}
int main()
{
	int n,i;
	point pt,p1,p2;
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf",&pt.x,&pt.y);
		p1=rotate(pt);
		p2=rotate(p1);
		if(zero(p1.y-p2.y))
		{
			if(p1.x>p2.x)
				swap(p1,p2);
		}
		else
		{
			if(p1.y>p2.y)
				swap(p1,p2);
		}
		printf("%.3lf %.3lf %.3lf %.3lf\n",p1.x,p1.y,p2.x,p2.y);
	}
   return 0;
}