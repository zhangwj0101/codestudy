////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-01 18:59:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2058
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cmath>
using namespace std;

void main()
{
    int n,m,i,j,sum;
    while(scanf("%d%d",&n,&m),n||m){
		int l=1+int(sqrt(double(m*2)));
		for(int i=l;i>0;i--){
			if((2*m)%i) continue;
			if((2*m/i-i+1)&1) continue;
			int t=m/i,s,e;
			if(i&1) s=t-(i-1)/2,e=t+(i-1)/2;
			else s=t-(i-2)/2,e=t+i/2;
			if(s>0&&e<=n)
				printf("[%d,%d]\n",s,e);
		}
		printf("\n");
    }
}