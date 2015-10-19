////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 13:03:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2108
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct point{int x,y;}p[5];
bool convex=1;
void judge(point p0,point p1,point p2)
{
	if((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)<0)
		convex=0;
}
int main()
{
	int n,i;
	while(cin>>n&&n)
	{
		convex=1;
		for(i=0;i<2;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i+2]=p[i];
		}
		n-=2;
		while(n--)
		{
			scanf("%d%d",&p[4].x,&p[4].y);
			judge(p[2],p[3],p[4]);
			p[2]=p[3];
			p[3]=p[4];
		}
		judge(p[2],p[3],p[0]);
		judge(p[3],p[0],p[1]);
		puts(convex?"convex":"concave");
	}
	return 0;
}