////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-14 17:54:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1264
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;

struct Seg_Tree{
	int left,right;
	int len,cvr;
}STree[600];

struct Seg{
	int left,right;
	int hight,side;
}seg[20000];

bool cmp(const Seg& a,const Seg& b){
	return a.hight<b.hight;
}

void Build(int left,int right,int idx){
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].cvr=0;
	STree[idx].len=0;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Update(int idx){
	if(STree[idx].cvr){
		STree[idx].len=STree[idx].right-STree[idx].left+1;
	}else{
		if(STree[idx].left==STree[idx].right){
			STree[idx].len=0;
		}else{
			STree[idx].len=STree[idx<<1].len+STree[idx<<1|1].len;
		}
	}
}

void Modify(int left,int right,int idx,int val){
	if(STree[idx].left==left&&STree[idx].right==right){
		STree[idx].cvr+=val;
		Update(idx);
		return;
	}
	//if(STree[idx].cvr){
	//	STree[idx<<1].cvr=STree[idx<<1|1].cvr=STree[idx].cvr;
	//	STree[idx<<1].len=STree[idx<<1].right-STree[idx<<1].left;
	//	STree[idx<<1|1].len=STree[idx<<1|1].right-STree[idx<<1|1].left;
	//	STree[idx].cvr=0;
	//}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(right<=mid){
		Modify(left,right,idx<<1,val);
	}else if(left>mid){
		Modify(left,right,idx<<1|1,val);
	}else{
		Modify(left,mid,idx<<1,val);
		Modify(mid+1,right,idx<<1|1,val);
	}
	Update(idx);
}

int main(){
	int x1,x2,y1,y2,t=0;
	while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF){
		if(x1<0){
			Build(0,100,1);
			sort(seg,seg+t*2,cmp);
			int Sum=0;
			for(int i=0;i<t*2-1;i++){
				Modify(seg[i].left,seg[i].right-1,1,seg[i].side);
				Sum+=STree[1].len*(seg[i+1].hight-seg[i].hight);
			}
			printf("%d\n",Sum);
			t=0;
			if(x1==-2) break;
		}else{
			if(x2<x1) x1^=x2^=x1^=x2;
			if(y2<y1) y1^=y2^=y1^=y2;
			seg[t<<1].left=seg[t<<1|1].left=x1;
			seg[t<<1].right=seg[t<<1|1].right=x2;
			seg[t<<1].hight=y1;
			seg[t<<1|1].hight=y2;
			seg[t<<1].side=1;
			seg[t<<1|1].side=-1;
			t++;
		}
	}
}