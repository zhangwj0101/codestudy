////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 15:58:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2838
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1772KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define M 100005
#define LL long long
#define lowbit(x) (x&(-x))

LL sum[M],cnt[M];
void modify(int p,int n){
	for(int i=p;i<=n;i+=lowbit(i)){
		sum[i]+=p;
		cnt[i]+=1;
	}
}

LL query(int l,int n){
	LL tsum=0,tcnt=0;
	for(int i=n;i;i-=lowbit(i)){
		tsum+=sum[i];
		tcnt+=cnt[i];
	}
	for(int i=l;i;i-=lowbit(i)){
		tsum-=sum[i];
		tcnt-=cnt[i];
	}
	return tsum+tcnt*l;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(sum,0,sizeof(sum));
		memset(cnt,0,sizeof(cnt));
		LL ans=0;
		for(int i=1;i<=n;i++){
			int num;
			scanf("%d",&num);
			ans+=query(num,100000);
			modify(num,100000);
		}
		printf("%I64d\n",ans);
	}
}