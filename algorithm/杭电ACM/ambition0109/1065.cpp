////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-21 16:56:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1065
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cmath>
using namespace std;
#define PI 3.1415926

int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		double x,y,dis;
		scanf("%lf%lf",&x,&y);
		dis=(x*x+y*y)*PI/2;
		printf("Property %d: This property will begin eroding in year %d.\n",++cas,int((dis+50.0-1e-6)/50.0));
	}
	puts("END OF OUTPUT.");
}
