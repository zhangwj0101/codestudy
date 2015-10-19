////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-30 13:50:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:3264KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;
struct Node{
	int left,right;
	int cvr;
}STree[400000];

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

void Build(int left,int right,int idx)
{
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].cvr=-1;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Modify(int left,int right,int idx,int val){
	if(STree[idx].left==left&&STree[idx].right==right){
		STree[idx].cvr=val;
		return;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(STree[idx].cvr!=-1){
		STree[idx<<1].cvr=STree[idx].cvr;
		STree[idx<<1|1].cvr=STree[idx].cvr;
		STree[idx].cvr=-1;
	}
	if(right<=mid){
		Modify(left,right,idx<<1,val);
	}else if(mid<left){
		Modify(left,right,idx<<1|1,val);
	}else{
		Modify(left,mid,idx<<1,val);
		Modify(mid+1,right,idx<<1|1,val);
	}
}

int Sum(int left,int right,int idx)
{
	if(STree[idx].cvr!=-1){
		return STree[idx].cvr*(right-left+1);
	}
	int mid=(left+right)>>1;
	return Sum(left,mid,idx<<1)+Sum(mid+1,right,idx<<1|1);
}

int main(){
	int t,c=0;
	scan_ud(t);
	while(t--){
		int n,q;
		scan_ud(n);
		scan_ud(q);
		Build(1,n,1);
		Modify(1,n,1,1);
		for(int i=0;i<q;i++){
			int l,r,v;
			scan_ud(l);
			scan_ud(r);
			scan_ud(v);
			Modify(l,r,1,v);
		}
		printf("Case %d: The total value of the hook is %d.\n",++c,Sum(1,n,1));
	}
}