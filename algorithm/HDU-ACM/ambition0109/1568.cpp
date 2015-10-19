////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-21 17:06:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1568
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cmath>
using namespace std;

int Fib[]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n<21){
			printf("%d\n",Fib[n]);
		}else{
			double ffour=-0.5*(log10(5.0))+n*log10((sqrt(5.0)+1.0)/2.0);
            ffour=pow(10.0,double(ffour-(int)ffour));
            while(ffour<1000) ffour*=10;
            printf("%d\n",int(ffour));
		}
	}
}