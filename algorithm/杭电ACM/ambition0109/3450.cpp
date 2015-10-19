////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-23 11:42:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3450
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:928KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))

int m,n;
int nn[100010],mm[100010];
int Index[100010];
int Disc[100010];
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

int Get_d(int num){
	int top=m,bottom=1;
	int mid=(top+bottom)/2,ans=mid;
	while(top>=bottom){
		if(num>Disc[mid]){
			bottom=mid+1;
		}else{
			top=(ans=mid)-1;
		}
		mid=(top+bottom)/2;
	}
	return ans;
}
int Get_u(int num){
	int top=m,bottom=1;
	int mid=(top+bottom)/2,ans=mid;
	while(top>=bottom){
		if(num>=Disc[mid]){
			bottom=(ans=mid)+1;
		}else{
			top=mid-1;
		}
		mid=(top+bottom)/2;
	}
	return ans;
}

int main()
{
	int k;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",nn+i);
			mm[i]=nn[i];
		}
		sort(mm,mm+n);
		Disc[1]=mm[0];m=1;
		for(int i=1;i<n;i++){
			if(mm[i]!=mm[i-1]){
				Disc[++m]=mm[i];
			}
		}
		memset(Index,0,sizeof(Index));
		for(int i=0;i<n;i++){
			int p=Get_u(nn[i]);
			int u=Get_u(nn[i]+k);
			int d=Get_d(nn[i]-k);
			int sum=(Sum(u)-Sum(d-1)+1)%9901;
			Add(p,sum,m);
		}
		int SS=(Sum(m)-n)%9901;
		printf("%d\n",SS);
	}
}