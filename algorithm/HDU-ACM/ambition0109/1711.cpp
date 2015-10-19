////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-14 09:48:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1711
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:4168KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int fail[10010];
void KMP(int B[],int m){
	fail[0]=-1;
	for(int i=1,j=-1;i<m;i++){
		while(j>=0&&B[j+1]!=B[i]) j=fail[j];
		if(B[j+1]==B[i])j ++;
		fail[i]=j;
	}
}
int match(int A[],int B[],int n,int m){
	for (int i=0,j=0;i<n;i++){
		while(j&&B[j]!= A[i]){
			j=fail[j-1]+1;
		}
		if(B[j]==A[i]) j++;
		if(j == m) return i-m+2;
	}
	return -1;
}

int nn[1000010],mm[10010];
int main()
{
	int n,m,t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&nn[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&mm[i]);
		}
		KMP(mm,m);
		printf("%d\n",match(nn,mm,n,m));
	}
}