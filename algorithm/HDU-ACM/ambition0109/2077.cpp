////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-02 18:58:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2077
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:176KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int t,n;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",int(pow(3.,double(n-1)))+1);
	}
}