////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-27 09:35:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2227
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:1748KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))

int n,m;
int Index[100010];
int numA[100010],numB[100010];
int Hash[100010];

inline bool scan_ud(int &num)
{
	char in;
	in=getchar();
	if(in==EOF) return false;
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	return true;
}

int Sum(int t)
{
	int sum=0;
	while(t>0){
		sum+=Index[t];
		if(sum>1000000007){
			sum%=1000000007;
		}
		t-=Lowbit(t);
	}
	return sum;
}

void Add(int pos,int num,int N)
{
	while(pos<=N){
		Index[pos]+=num;
		if(Index[pos]>1000000007){
			Index[pos]%=1000000007;
		}
		pos+=Lowbit(pos);
	}
}

int find(int num){
	int top=1,bottom=m,mid=(top+bottom)/2,ans=mid;
	while(num!=Hash[ans]){
		if(Hash[mid]<=num){
			top=(ans=mid)+1;
		}else{
			bottom=mid-1;
		}
		mid=(top+bottom)/2;
	}
	return ans;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for (int i = 0; i < n; i ++){
			scan_ud(numA[i]);
			numB[i] = numA[i];
		}
		sort(numB,numB+n);
		Hash[1]=numB[0];m=1;
		for (int i = 1; i < n; i++){
			if(numB[i] != numB[i - 1] )
				Hash[++m] = numB[i];
		}
		memset(Index, 0, sizeof(Index));
		for (int i = 0; i < n; i++){
			int idx = find(numA[i]);
			int temp = Sum(idx) + 1;
			Add(idx, temp,m);
		}
		printf("%d\n", Sum(m));
	}
}