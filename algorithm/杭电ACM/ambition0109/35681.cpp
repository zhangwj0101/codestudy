////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-25 10:22:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3568
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:1352KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int num[100001];
__int64 sum[100001];
int main(){
	int n,t,c=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%d%I64d",num,sum);
		for(int i=1;i<n;i++){
			int tmp;
			scanf("%d%d",num+i,&tmp);
			sum[i]=sum[i-1]+tmp;
		}
		__int64 SS=0;
		for(int i=0;i<n;i++){
			if(i>0) SS+=(__int64)num[i]*sum[i-1];
			if(i<n-1) SS+=(__int64)num[i]*(sum[n-1]-sum[i]);
		}
		printf("Case %d: %I64d\n",++c,SS);
	}
}