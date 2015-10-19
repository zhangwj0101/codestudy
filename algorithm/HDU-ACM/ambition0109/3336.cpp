////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-16 14:38:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3336
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1940KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=200050;

char str[MAXN+1];
int Fail[MAXN+1];
int sum[MAXN+1];

void GetFail(char num[],int m){
	Fail[0]=-1;sum[0]=1;
	for(int i=1,j=-1;i<m;i++){
		while(j>=0&&num[j+1]!=num[i]){
			j=Fail[j];
		}
		if(num[j+1]==num[i]) j++;
		Fail[i]=j;
		if(j==-1) sum[i]=1;
		else sum[i]=sum[j]+1;
	}
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",&str);
		GetFail(str,n);
		int ss=0;
		for(int i=0;i<n;i++){
			ss+=sum[i];
			if(ss>=10007){
				ss%=10007;
			}
		}
		printf("%d\n",ss);
	}
}