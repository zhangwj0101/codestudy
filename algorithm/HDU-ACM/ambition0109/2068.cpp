////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-03 10:59:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2068
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<string>
using namespace std;

__int64 num[15];
__int64 ans[26];
int main()
{
	num[1]=0;num[2]=1;
	for(int i=3;i<15;i++){
		num[i]=(i-1)*(num[i-1]+num[i-2]);
	}
	for(int i=1;i<26;i++){
		ans[i]=1;
		for(int j=1,k=i;j<=i/2;j++){
			ans[i]+=k*num[j];
			k*=(i-j);
			k/=(j+1);
		}
	}
	int n;
	while(scanf("%d",&n),n){
		printf("%I64d\n",ans[n]);
	}
} 