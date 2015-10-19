////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-17 15:02:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2443
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1360KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))
int Idx[100005];
int sum[100005];
int Dis[100005];

inline void scan_ud(int &num)
{
	char in;
	in=getchar();
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
}

void Modify(int pos,int max)
{
	for(int i=pos;i<=max;i+=Lowbit(i)){
		Idx[i]+=1;
	}
}

int Query(int pos){
	int Sum=0;
	for(int i=pos;i;i-=Lowbit(i)){
		Sum+=Idx[i];
	}
	return Sum;
}

int Find(int val,int max)
{
	int top=1,bot=max;
	int mid=(top+bot)>>1;
	while(true){
		if(Dis[mid]==val){
			return mid;
		}else if(Dis[mid]>val){
			bot=mid-1;
		}else if(Dis[mid]<val){
			top=mid+1;
		}
		mid=(top+bot)>>1;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,ave,cnt=0;
		scanf("%d%d",&n,&ave);
		memset(Idx,0,sizeof(Idx));
		__int64 Sum=0;
		sum[1]=Dis[1]=-ave;
		for(int i=2;i<=n+1;i++){
			int tmp;
			scan_ud(tmp);
			tmp-=ave;
			sum[i]=sum[i-1]+tmp;
			Dis[i]=sum[i];
		}
		sort(Dis+1,Dis+n+2);
		int m=1;
		for(int i=2;i<=n+1;i++){
			if(Dis[m]!=Dis[i]){
				Dis[++m]=Dis[i];
			}
		}
		for(int i=1;i<=n+1;i++){
			int tp=Find(sum[i],m);
			Modify(tp,m);
			Sum+=Query(tp-1);
		}
		printf("%I64d\n",Sum);
	}
}