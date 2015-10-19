////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-12 12:54:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2639
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:328KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int v[101] , w[101];
int dp[1001][31];
int sz[1001];
int K;

void Merge(int A[],int sza,int w,int B[],int &szb) {
	int C[31] , sz = 0;
	int i = 0, j = 0;
	while (i < sza && j < szb && sz < K) {
		if(A[i]+w < B[j]) {
			C[sz++] = B[j++];
		} else if(A[i] + w == B[j]) {
			C[sz++] = B[j];
			i ++ , j ++;
		} else {
			C[sz++] = A[i++]+ w;
		}
	}
	while(i < sza && sz < K) {
		C[sz++] = A[i++] + w;
	}
	while(j < szb && sz < K) {
		C[sz++] = B[j++];
	}
	szb = sz;
	for (int i =0 ; i < sz ; i ++) {
		B[i] = C[i];
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n , m;
		scanf("%d%d%d",&n,&m,&K);
		for (int i = 0 ; i < n ; i ++) scanf("%d",&w[i]);
		for (int i = 0 ; i < n ; i ++) scanf("%d",&v[i]);
		for (int i = 0 ; i <= m ; i ++) sz[i] = 0;
		dp[0][0] = 0;
		sz[0] = 1;
		for (int i = 0 ; i < n ; i ++) {
			for (int j = m ; j >= v[i] ; j --) {
				Merge(dp[j-v[i]] , sz[j-v[i]] , w[i] , dp[j] , sz[j]);
			}
		}
		int ssz=0;
		int arr[31];
		for (int i = 0 ; i <= m ; i ++) {
			Merge(dp[i] , sz[i] , 0 , arr , ssz);
		}
		if(ssz != K) {
			puts("0");
		} else {
			printf("%d\n",arr[ssz-1]);
		}
	}
	return 0;
}
