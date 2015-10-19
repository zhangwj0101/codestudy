////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-09 13:55:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2795
////Problem Title: 
////Run result: Accept
////Run time:1500MS
////Run memory:6380KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int Len;
struct Node{
	int left,right;
	int max;
}STree[800000];

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

int Max(int a,int b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

int Min(int a,int b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

void Build(int left,int right,int idx){
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].max=Len;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

int Modify(int len,int idx){
	if(STree[idx].left==STree[idx].right){
		if(STree[idx].max>=len){
			STree[idx].max-=len;
			return STree[idx].left;
		}else{
			return -1;
		}
	}
	int ans;
	if(STree[idx<<1].max>=len){
		ans=Modify(len,idx<<1);
		STree[idx].max=Max(STree[idx<<1].max,STree[idx<<1|1].max);
	}else if(STree[idx<<1|1].max>=len){
		ans=Modify(len,idx<<1|1);
		STree[idx].max=Max(STree[idx<<1].max,STree[idx<<1|1].max);
	}else{
		ans=-1;
	}
	return ans;
}

int main()
{
	int n,q;
	while(scanf("%d%d%d",&n,&Len,&q)!=EOF){
		int t=Min(n,q);
		Build(1,t,1);
		while(q--){
			scan_ud(t);
			printf("%d\n",Modify(t,1));
		}
	}
}