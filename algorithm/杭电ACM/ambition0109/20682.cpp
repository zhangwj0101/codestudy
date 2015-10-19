////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-03 11:09:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2068
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

__int64 ans[26]={0,1,1,1,7,11,56,92,771,1339,13264,23684,284670,
	518454,7256640,13402248,214442403,400221651,7203965408,
	13554359252,271087277418,513349865698,11293696692640,
	21498814787768,515971556258510,986478419687006};
int main()
{
	int n;
	while(scanf("%d",&n),n){
		printf("%I64d\n",ans[n]);
	}
} 