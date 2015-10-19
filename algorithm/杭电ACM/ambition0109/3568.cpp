////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-25 10:18:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3568
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:2528KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int numA[100001],numB[100001];
__int64 sumA[100001],sumB[100001];
int main(){
	int n,t,c=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%d%d",numA,numB);
		sumA[0]=numA[0],sumB[0]=numB[0];
		for(int i=1;i<n;i++){
			scanf("%d%d",numA+i,numB+i);
			sumA[i]=sumA[i-1]+numA[i];
			sumB[i]=sumB[i-1]+numB[i];
		}
		__int64 SS=0;
		for(int i=1;i<n;i++){
			SS+=(__int64)numA[i]*sumB[i-1];
			SS+=(__int64)numB[i]*sumA[i-1];
		}
		printf("Case %d: %I64d\n",++c,SS);
	}
}