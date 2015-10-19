////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-27 19:39:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2299
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
struct point{
	int x,y;
};

double getarea(point p0,point p1,point p2){
	return fabs(double((p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y))/2.);
}
point pp[51];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d%d",&pp[i].x,&pp[i].y);
		double max=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for(int k=j+1;k<n;k++){
					double temp=getarea(pp[i],pp[j],pp[k]);
					if(temp>max) max=temp;
				}
		printf("%.1lf\n",max);
	}
}