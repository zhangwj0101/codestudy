////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-03 14:59:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1779
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:5376KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

struct Node{
	int left,right;
	int val,cvr,msite;
}STree[270000];

struct Res{
	int idx,val;
};

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
	STree[idx].cvr=0;
	STree[idx].val=0;
	STree[idx].msite=left;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Modify(int left,int right,int idx,int val){
	if(STree[idx].left==left&&STree[idx].right==right){
			STree[idx].cvr+=val;
			STree[idx].val+=val;
			return;
	}
	if(STree[idx].cvr){
		STree[idx<<1].val+=STree[idx].cvr;
		STree[idx<<1].cvr+=STree[idx].cvr;
		STree[idx<<1|1].val+=STree[idx].cvr;
		STree[idx<<1|1].cvr+=STree[idx].cvr;
		STree[idx].cvr=0;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(right<=mid){
		Modify(left,right,idx<<1,val);
	}else if(left>mid){
		Modify(left,right,idx<<1|1,val);
	}else{
		Modify(left,mid,idx<<1,val);
		Modify(mid+1,right,idx<<1|1,val);
	}
	if(STree[idx<<1].val>=STree[idx<<1|1].val){
		STree[idx].val=STree[idx<<1].val;
		STree[idx].msite=STree[idx<<1].msite;
	}else{
		STree[idx].val=STree[idx<<1|1].val;
		STree[idx].msite=STree[idx<<1|1].msite;
	}
}

Res Query(int left,int right,int idx){
	if(STree[idx].left==left&&STree[idx].right==right){
		Res res;
		res.idx=STree[idx].msite;
		res.val=STree[idx].val;
		return res;
	}
	if(STree[idx].cvr){
		STree[idx<<1].val+=STree[idx].cvr;
		STree[idx<<1].cvr+=STree[idx].cvr;
		STree[idx<<1|1].val+=STree[idx].cvr;
		STree[idx<<1|1].cvr+=STree[idx].cvr;
		STree[idx].cvr=0;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(right<=mid){
		return Query(left,right,idx<<1);
	}else if(left>mid){
		return Query(left,right,idx<<1|1);
	}else{
		Res ml=Query(left,mid,idx<<1);
		Res mr=Query(mid+1,right,idx<<1|1);
		return (ml.val>=mr.val?ml:mr);
	}
}

int main()
{
	int n,m;
	while(scan_ud(n),scan_ud(m),n||m){
		Build(1,n,1);
		for(int i=0;i<m;i++){
			char cmd[2];
			scanf("%s",cmd);
			if(cmd[0]=='I'){
				int l,r,v;
				scan_ud(l);
				scan_ud(r);
				scan_ud(v);
				Modify(l,r,1,v);
			}else if(cmd[0]=='C'){
				int l,r;
				scan_ud(l);
				scan_ud(r);
				Res res=Query(l,r,1);
				printf("%d\n",res.val);
				Modify(res.idx,res.idx,1,-res.val);
			}
		}
	}
}