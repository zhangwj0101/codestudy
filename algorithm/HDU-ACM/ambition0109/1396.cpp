////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-19 11:45:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1396
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		long long sum;
		sum=n*(n+1)*(n+2)/6;
		for(int i=1;n-2*i+1>0;i++){
			sum+=(n-2*i+1)*(n-2*i+2)/2;
		}
		printf("%lld\n",sum);
	}
}
