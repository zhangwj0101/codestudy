////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-25 16:43:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3030
////Problem Title: 
////Run result: Accept
////Run time:3453MS
////Run memory:13904KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))

__int64 Index[500010];
int numA[500010],numB[500010];
__int64 Dis[500010],tmp[500010];
int n;
int Sum(int t)
{
	__int64 sum=0;
	while(t>0){
		sum+=Index[t];
		if(sum>=1000000007){
			sum%=1000000007;
		}
		t-=Lowbit(t);
	}
	return int(sum);
}

void Add(int Pos,int Num)
{
	while(Pos<=n){
		Index[Pos]+=Num;
		Pos+=Lowbit(Pos);
	}
}

int qfind(int t,int m)
{
	int low=1,high=m;
	int mid=(low+high)/2,ans=mid;
	while(low<=high){
		if(Dis[mid]<=t){
			low=(ans=mid)+1;
		}else{
			high=mid-1;
		}
		mid=(low+high)/2;
	}
	return ans;
}

int main()
{
	int t,c=0;
	scanf("%d",&t);
	while(t--){
		memset(Index,0,sizeof(Index));
		int m,x,y,z;
		scanf("%d%d%d%d%d",&n,&m,&x,&y,&z);
		x=x%z,y=y%z;
		for(int i=0;i<m;i++){
			scanf("%d",&numA[i]);
			tmp[i]=numB[i]=numA[i];
			numA[i]=(__int64(numA[i])*x+__int64(i+1)*(y))%z;
		}
		for(int i=m;i<n;i++){
			numB[i]=numA[i%m];
			tmp[i]=numB[i];
			numA[i%m]=(__int64(numA[i%m])*x+__int64(i+1)*(y))%z;
		}
		sort(tmp,tmp+n);
		int d=1;Dis[1]=tmp[0];
		for(int i=1;i<n;i++){
			if(tmp[i]!=tmp[i-1]){
				Dis[++d]=tmp[i];
			}
		}
		for(int i=0;i<n;i++){
			int Pos=qfind(numB[i],d);
			Add(Pos,Sum(Pos-1)+1);
		}
		printf("Case #%d: %d\n",++c,Sum(d));
	}
}