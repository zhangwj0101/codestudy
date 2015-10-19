////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-16 11:29:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2594
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:476KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=50010;
const int MAXM=50010;

char nn[MAXN+1],mm[MAXM+1];
int Fail[MAXM+1];

void GetFail(char num[],int m){
	Fail[0]=-1;
	for(int i=1,j=-1;i<m;i++){
		while(j>=0&&num[j+1]!=num[i]){
			j=Fail[j];
		}
		if(num[j+1]==num[i])j ++;
		Fail[i]=j;
	}
}
int KMP(char numA[],char numB[],int n,int m){
	int j=0;
	for (int i=0;i<n;i++){
		while(j&&numB[j]!=numA[i]){
			j=Fail[j-1]+1;
		}
		if(numB[j]==numA[i]) j++;
		if(i!=n-1&&j==m) j=Fail[j-1]+1;
	}
	return j;
}

int main(){
	while(scanf("%s %s",&nn,&mm)!=EOF){
		int lenn=int(strlen(nn));
		int lenm=int(strlen(mm));
		GetFail(nn,lenm);
		int kmp;
		kmp=KMP(mm,nn,lenm,lenn);
		if(kmp==0){
			puts("0");
		}else{
			nn[kmp]='\0';
			printf("%s %d\n",nn,kmp);
		}
	}
}