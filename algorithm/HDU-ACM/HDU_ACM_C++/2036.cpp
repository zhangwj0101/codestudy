////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-02 11:25:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
//可能为负的
#include<iostream>
#include<cmath>
using namespace std;
struct point
{
	double x,y;
}p[101];
double xmult(point p1,point p2,point p0)   //求三角形的面积，二阶行列式
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int main()                                     //对于每个测试实例，请输出对应的多边形面积，结果精确到小数点后一位小数。每个实例的输出占一行
{
	double s;
	int n,i;
	while((scanf("%d",&n)==1)&&n)          //输入成功，并且n!=0
	{
		for(i=0;i<n;i++)                    //依次输入n个顶点，保存在顶点数据结构中
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for(s=0,i=1;i<n-1;i++)
			s+=xmult(p[0],p[i],p[i+1])/2;
		printf("%.1lf\n",s);
	}
   return 0;
}