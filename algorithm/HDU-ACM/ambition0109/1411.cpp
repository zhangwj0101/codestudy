////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-19 14:37:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1411
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cmath>
using namespace std;
#define COS(a,b,c) ((a*a+b*b-c*c)/(2*a*b))

int main(){
	double ab,ac,ad,bc,bd,cd;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&ab,&ac,&ad,&bc,&bd,&cd)){
		double ans,c1=COS(ab,ac,bc),c2=COS(ab,ad,bd),c3=COS(ac,ad,cd);
		ans=ab*ac*ad*sqrt(1.0+2*c1*c2*c3-c1*c1-c2*c2-c3*c3)/6.0;
		printf("%.4lf\n",ans);
	}

}
