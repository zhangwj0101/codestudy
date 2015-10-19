////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-14 10:12:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1711
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:4168KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;
const int MAXN=1000000;
const int MAXM=10000;

inline bool scan_d(int &num)
{
	char in;bool IsN=false;
	in=getchar();
	if(in==EOF) return false;
	while(in!='-'&&(in<'0'||in>'9')) in=getchar();
	if(in=='-'){ IsN=true;num=0;}
	else num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	if(IsN) num=-num;
	return true;
}

int Fail[MAXM+1];
void GetFail(int num[],int m){
	Fail[0]=-1;
	for(int i=1,j=-1;i<m;i++){
		while(j>=0&&num[j+1]!=num[i]){
			j=Fail[j];
		}
		if(num[j+1]==num[i])j ++;
		Fail[i]=j;
	}
}
int KMP(int numA[],int numB[],int n,int m){
	for (int i=0,j=0;i<n;i++){
		while(j&&numB[j]!=numA[i]){
			j=Fail[j-1]+1;
		}
		if(numB[j]==numA[i]) j++;
		if(j == m) return i-m+1;
	}
	return -1;
}

int nn[MAXN+1],mm[MAXM+1];
int main()
{
	int n,m,t;scan_d(t);
	while(t--){
		scan_d(n);scan_d(m);
		for(int i=0;i<n;i++){
			scan_d(nn[i]);
		}
		for(int i=0;i<m;i++){
			scan_d(mm[i]);
		}
		GetFail(mm,m);
		int ans=KMP(nn,mm,n,m);
		if(ans!=-1){
			printf("%d\n",ans+1);
		}else{
			puts("-1");
		}
	}
}