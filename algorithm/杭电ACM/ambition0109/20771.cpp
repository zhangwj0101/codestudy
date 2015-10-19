////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-02 19:08:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2077
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:172KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int bPow(int num,int p){
	int ans=1;
	for(;p;p>>=1){
		if(p&1) ans*=num;
		num*=num;
	}
	return ans;
}
int main()
{
	int t,n;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",bPow(3,n-1)+1);
	}
}