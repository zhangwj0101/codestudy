////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-10 20:42:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3432
////Problem Title: 
////Run result: Accept
////Run time:1390MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void main()
{
	int w,h,d,n;
	while(scanf("%d%d%d%d",&w,&h,&d,&n),w||h||d||n)
	{
		double ss=(double)(w*h);double dd=ss/(double)n,ds;
		for(int i=1;i<n;i++)
		{
			ds=dd*(double)i;
			double temp;
			if(i!=1) printf(" ");
			if((double)((w-d)*h)/2.>=ds){
				temp=ds/(double)(w-d)*2.;
				printf("%.3lf %.3lf",(double)w,temp);
			}else if((ss-(double)(d*h)/2.)>=ds){
				temp=(double)w-(ds-(double)((w-d)*h)/2.)/(double)h*2.;
				printf("%.3lf %.3lf",temp,(double)h);
			}else{
				temp=((ss-ds)/(double)d*2.);
				printf("%.3lf %.3lf",0.,temp);
			}
		}
		printf("\n");
	}
}