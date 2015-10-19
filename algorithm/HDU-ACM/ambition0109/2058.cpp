////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-01 18:52:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2058
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<iostream>
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
			int t=m/i;
			if(i&1){
				if(t>(i-1)/2&&t+(i-1)/2<=n)
					printf("[%d,%d]\n",t-(i-1)/2,t+(i-1)/2);
			}else{
				if(t>(i-2)/2&&t+i/2<=n)
					printf("[%d,%d]\n",t-(i-2)/2,t+i/2);
			}
		}
		printf("\n");
    }
}