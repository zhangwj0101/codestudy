////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-16 13:12:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3714
////Problem Title: 
////Run result: Accept
////Run time:703MS
////Run memory:428KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

double a[10005],b[10005],c[10005];
int n;
double get(double x){
	double max=-1e10;
	for(int i=0;i<n;i++){
		double t=a[i]*x*x+b[i]*x+c[i];
		if(t>max) max=t;
	}
	return max;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
		}
		double top=0.0,bot=1000.0;
		double ft=(top*2.0+bot)/3.0,st=(top+bot*2.0)/3.0;
		while(st-ft>1e-10){
			if(get(ft)>=get(st)){
				top=ft;
			}else{
				bot=st;
			}
			ft=(top*2.0+bot)/3.0;
			st=(top+bot*2.0)/3.0;
		}
		printf("%.4lf\n",get(ft));
	}
}