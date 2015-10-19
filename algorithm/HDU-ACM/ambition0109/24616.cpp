////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-08 11:45:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2461
////Problem Title: 
////Run result: Accept
////Run time:1015MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Seg_Tree{
	int left,right,cvr;
	int len;
}STree[200];
int Dis[45];

struct Seg{
	int left,right,hight;
	int side,id;
}seg[45];
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

void Update(int idx){
	if(STree[idx].cvr){
		STree[idx].len=Dis[STree[idx].right]-Dis[STree[idx].left];
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

int Find(int val,int max){
	int top=2,bot=max;
	int mid=(max+2)>>1;
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

int main(){
	int n,m,cas=0;
	while(scanf("%d%d",&n,&m),n||m){
		int x1,x2,y1,y2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			Dis[i<<1]=seg[i<<1].left=seg[i<<1|1].left=x1;
			Dis[i<<1|1]=seg[i<<1].right=seg[i<<1|1].right=x2;
			seg[i<<1].hight=y1; seg[i<<1].side=1; seg[i<<1].id=i;
			seg[i<<1|1].hight=y2; seg[i<<1|1].side=-1; seg[i<<1|1].id=i;
		}
		sort(Dis+2,Dis+2*n+2);
		sort(seg+2,seg+2*n+2,cmp);
		int mmax=2;
		for(int i=3;i<2*n+2;i++){
			if(Dis[mmax]!=Dis[i]){
				Dis[++mmax]=Dis[i];
			}
		}
		Build(2,mmax,1);
		printf("Case %d:\n",++cas);
		for(int i=0;i<m;i++){
			int r,thash=0;
			scanf("%d",&r);
			for(int j=0;j<r;j++){
				int tr;
				scanf("%d",&tr);
				thash+=1<<(tr-1);
			}
			int ttr[45];
			for(int j=2,tm=0;j<2*n+2;j++){
				if(thash&(1<<(seg[j].id-1))){
					ttr[tm++]=j;
				}
			}
			int Sum=0;
			for(int j=0;j<2*r-1;j++){
				int pl=Find(seg[ttr[j]].left,mmax);
				int pr=Find(seg[ttr[j]].right,mmax);
				Modify(pl,pr,seg[ttr[j]].side,1);
				Sum+=STree[1].len*(seg[ttr[j+1]].hight-seg[ttr[j]].hight);
			}
			int pl=Find(seg[ttr[2*r-1]].left,mmax);
			int pr=Find(seg[ttr[2*r-1]].right,mmax);
			Modify(pl,pr,seg[ttr[2*r-1]].side,1);
			printf("Query %d: %d\n",i+1,Sum);
		}
		puts("");
	}
}