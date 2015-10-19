////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-07 17:35:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2139
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int main()
{
	__int64 n;
	while(scanf("%I64d",&n)!=EOF){
		__int64 t=(n+2)*(n+1)*n/6;
		printf("%I64d\n",t);
	}
}