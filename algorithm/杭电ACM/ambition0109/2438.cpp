////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-17 13:12:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2438
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);

double x,y,l,d;
double Get(double ang){
	double t=tan(ang);
	double ty=y+t*x;
	double tx=y/t+x;
	double tl=sqrt(tx*tx+ty*ty);
	double td=tx*ty/tl;
	if(td<=d) return 0;
	return (td-d)/td*tl;
}

int main()
{
	while(scanf("%lf%lf%lf%lf",&x,&y,&l,&d)!=EOF){
		if(x<d||y<d) goto No;
		double top=0,bot=pi/2.0;
		double ft=(top*2.0+bot)/3.0;
		double st=(top+bot*2.0)/3.0;
		while(st-ft>10e-8){
			double tft=Get(ft);
			double tst=Get(st);
			if(tst<=l||tft<=l){
				goto No;
			}
			if(tst<tft){
				top=ft;
			}else{
				bot=st;
			}
			ft=(top*2.0+bot)/3.0;
			st=(top+bot*2.0)/3.0;
		}
		puts("yes");
		continue;
No:
		puts("no");
		continue;

	}
}