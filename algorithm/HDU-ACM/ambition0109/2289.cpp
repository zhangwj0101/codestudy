////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-29 19:58:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2289
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:168KB
//////////////////System Comment End//////////////////
/*
 * 2289.cpp
 *
 *  Created on: 2010-8-29
 *      Author: ambition
 */

#include<cstdio>
#include<cmath>
using namespace std;
#define pi 3.1415926535
#define V(r,R,h) (pi*h*(R*R+R*r+r*r)/3.0)

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		double r,R,h,v;
		scanf("%lf%lf%lf%lf",&r,&R,&h,&v);
		double top=0,rr=r;
		double bot=h,RR=R;
		double ft=(top*2.0+bot)/3.0;
		double st=(top+bot*2.0)/3.0;
		double fr=(rr*2.0+RR)/3.0;
		double sr=(rr+RR*2.0)/3.0;
		while(abs(bot-top)>1e-8){
			double vf=abs(V(fr,r,ft)-v);
			double vs=abs(V(sr,r,st)-v);
			if(vf>vs){
				top=ft;
				rr=fr;
			}else{
				bot=st;
				RR=sr;
			}
			fr=(rr*2.0+RR)/3.0;
			sr=(rr+RR*2.0)/3.0;
			ft=(top*2.0+bot)/3.0;
			st=(top+bot*2.0)/3.0;
		}
		printf("%.6lf\n",ft);
	}
}
