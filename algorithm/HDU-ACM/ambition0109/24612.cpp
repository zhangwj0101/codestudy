////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-08 11:23:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2461
////Problem Title: 
////Run result: Accept
////Run time:3906MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Seg_Tree{
	int left,right,cvr;
	int len;
}STree[4000];

struct Seg{
	int left,right,hight;
	int side,id;
}seg[80];
bool cmp(const Seg& a,const Seg& b){
	return a.hight<b.hight;
}

void Build(int left,int right,int idx){
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].cvr=0;
	STree[idx].len=0;
	if(right-left==1) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid,right,idx<<1|1);
}

void Init(int left,int right,int idx){
	STree[idx].cvr=0;
	STree[idx].len=0;
	if(right-left==1) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid,right,idx<<1|1);
}

void Update(int idx){
	if(STree[idx].cvr){
		STree[idx].len=STree[idx].right-STree[idx].left;
	}else{
		if(STree[idx].right-STree[idx].left==1){
			STree[idx].len=0;
		}else{
			STree[idx].len=STree[idx<<1].len+STree[idx<<1|1].len;
		}
	}
}

void Modify(int left,int right,int val,int idx){
	if(STree[idx].left==left&&STree[idx].right==right){
		STree[idx].cvr+=val;
		Update(idx);
		return;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(right<=mid){
		Modify(left,right,val,idx<<1);
	}else if(left>=mid){
		Modify(left,right,val,idx<<1|1);
	}else{
		Modify(left,mid,val,idx<<1);
		Modify(mid,right,val,idx<<1|1);
	}
	Update(idx);
}

int main(){
	int n,m,cas=0;
	Build(0,1000,1);
	while(scanf("%d%d",&n,&m),n||m){
		int x1,x2,y1,y2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			seg[i<<1].left=seg[i<<1|1].left=x1;
			seg[i<<1].right=seg[i<<1|1].right=x2;
			seg[i<<1].hight=y1;
			seg[i<<1|1].hight=y2;
			seg[i<<1].side=1; seg[i<<1].id=i;
			seg[i<<1|1].side=-1; seg[i<<1|1].id=i;
		}
		sort(seg+2,seg+2*n+2,cmp);
		printf("Case %d:\n",++cas);
		for(int i=0;i<m;i++){
			int r,thash=0;
			scanf("%d",&r);
			for(int j=0;j<r;j++){
				int tr;
				scanf("%d",&tr);
				thash+=1<<(tr-1);
			}
			Init(0,1000,1);
			int ttr[80];
			for(int j=2,tm=0;j<2*n+2;j++){
				if(thash&(1<<(seg[j].id-1))){
					ttr[tm++]=j;
				}
			}
			int Sum=0;
			for(int j=0;j<2*r-1;j++){
				Modify(seg[ttr[j]].left,seg[ttr[j]].right,seg[ttr[j]].side,1);
				Sum+=STree[1].len*(seg[ttr[j+1]].hight-seg[ttr[j]].hight);
			}
			Modify(seg[ttr[2*r-1]].left,seg[ttr[2*r-1]].right,seg[ttr[2*r-1]].side,1);
			printf("Query %d: %d\n",i+1,Sum);
		}
		puts("");
	}
}