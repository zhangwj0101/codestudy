////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-08 19:34:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2608
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int sum,k;
		k=int(sqrt(double(n)));
		sum=k&1;
		for(int i=1;i<=k;i++){
			if(i*i*2>n) break;
			sum^=1;
		}
		printf("%d\n",sum);
	}
}