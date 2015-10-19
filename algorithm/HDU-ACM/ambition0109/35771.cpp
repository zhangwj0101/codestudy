////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-10 19:47:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3577
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:764KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;

int Dis[200000];
struct Seg_Tree{
	int left,right;
	int max;
}STree[600001];

inline int Max(int a,int b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

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

void Build(int left,int right,int idx)
{
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].max=0;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Modify(int left,int right,int idx){
	if(STree[idx].left==STree[idx].right){
		STree[idx].max+=1;
		return;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(right<=mid){
		Modify(left,right,idx<<1);
	}else if(mid<left){
		Modify(left,right,idx<<1|1);
	}else{
		Modify(left,mid,idx<<1);
		Modify(mid+1,right,idx<<1|1);
	}
	STree[idx].max=Max(STree[idx<<1].max,STree[idx<<1|1].max);
}

bool Query(int left,int right,int idx,int val){
	//if(STree[idx].max<val) return true;
	if(STree[idx].left==left&&STree[idx].right==right){
		if(STree[idx].max<val) return true;
		else return false;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(right<=mid){
		return Query(left,right,idx<<1,val);
	}else if(mid<left){
		return Query(left,right,idx<<1|1,val);
	}else{
		return Query(left,mid,idx<<1,val)&&Query(mid+1,right,idx<<1|1,val);
	}
}

int Find(int val,int m){
	int top=0,bot=m;
	int mid=(top+bot)>>1;
	while(true){
		if(Dis[mid]==val){
			return mid;
		}else if(Dis[mid]<val){
			top=mid+1;
		}else if(Dis[mid]>val){
			bot=mid-1;
		}
		mid=(top+bot)>>1;
	}
}

int l[10010],r[10010];
int main()
{
	int t,c=0;
	scanf("%d",&t);
	while(t--){
		int k,n;
		scan_ud(k);
		scan_ud(n);
		int max=0;
		for(int i=0;i<n;i++){
			scan_ud(l[i]);
			scan_ud(r[i]);
			Dis[i<<1]=l[i];
			Dis[i<<1|1]=r[i];
		}
		sort(Dis,Dis+2*n);
		int m=0;
		for(int i=1;i<2*n;i++){
			if(Dis[m]!=Dis[i]){
				Dis[++m]=Dis[i];
			}
		}
		Build(0,m,1);
		printf("Case %d:\n",++c);
		for(int i=0;i<n;i++){
			int pl=Find(l[i],m);
			int pr=Find(r[i],m)-1;
			if(Query(pl,pr,1,k)){
				printf("%d ",i+1);
				Modify(pl,pr,1);
			}
		}
		puts("\n");
	}
}