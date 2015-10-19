////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-16 14:02:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3443
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;


int main()
{
	long long n;
	while(scanf("%I64d",&n),n){
		long long min=n;
		long long mod=1;
		while(mod<n){
			mod*=10;
			mod+=1;
		}
		mod/=10;
		while(mod)
		{
			if(!(n%mod)){
				min=n/mod;
				break;
			}
			mod/=10;
		}
		printf("%I64d\n",min);
	}
	return 0;
}