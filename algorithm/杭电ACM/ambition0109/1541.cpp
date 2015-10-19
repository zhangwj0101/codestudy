////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-22 19:05:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1541
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:472KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(x^(x-1)))

int n,m;
int Index[15010];
int numA[15010],numB[15010];
int Hash[15010];

bool cmp(const int& a,const int& b){
	return a<b;
}
int Sum(int t)
{
	int sum=0;
	while(t>0){
		sum+=Index[t];
		t-=Lowbit(t);
	}
	return sum;
}

void Add(int pos,int num,int N)
{
	while(pos<=N){
		Index[pos]+=num;
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

int ans[15010];

int main()
{
	int n,temp;
	while(scanf("%d",&n)!=EOF){
		for (int i = 0; i < n; i ++){
			scanf("%d%d", numA + i,&temp);
			numB[i] = numA[i];
		}
		sort(numB,numB+n);
		m=0;
		for (int i = 0; i < n; i++){
			if(i == 0 || numB[i] != numB[i - 1] )
				Hash[++m] = numB[i];
		}
		memset(Index, 0, sizeof(Index));
		memset(ans,0,sizeof(ans));
		for (int i = 0; i < n; i++){
			int idx = find(numA[i]);
			ans[Sum(idx)]++;
			Add(idx,1,m);
		}
		for(int i=0;i<n;i++){
			printf("%d\n",ans[i]);
		}
	}
}