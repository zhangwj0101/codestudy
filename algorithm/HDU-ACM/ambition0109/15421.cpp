////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-14 19:49:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1542
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

struct Seg_STree{
	int left,right;
	int cvr;
	double len;
}STree[600];
double Dis[205];

struct Seg{
	double left,right;
	double hight;
	int side;
}seg[205];

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

int Find(double val,int max){
	int top=0,bot=max;
	int mid=max>>1;
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
	int n,c=0;
	while(scanf("%d",&n),n){
		double x1,y1,x2,y2;
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			Dis[i<<1]=seg[i<<1].left=seg[i<<1|1].left=x1;
			Dis[i<<1|1]=seg[i<<1].right=seg[i<<1|1].right=x2;
			seg[i<<1].hight=y1;
			seg[i<<1|1].hight=y2;
			seg[i<<1].side=1;
			seg[i<<1|1].side=-1;
		}
		sort(Dis,Dis+2*n);
		sort(seg,seg+2*n,cmp);
		int m=0;
		for(int i=1;i<2*n;i++){
			if(Dis[m]!=Dis[i]){
				Dis[++m]=Dis[i];
			}
		}
		Build(0,m,1);
		double Sum=0;
		for(int i=0;i<2*n-1;i++){
			int pl=Find(seg[i].left,m);
			int pr=Find(seg[i].right,m);
			Modify(pl,pr,seg[i].side,1);
			Sum+=STree[1].len*(seg[i+1].hight-seg[i].hight);
		}
		printf("Test case #%d\n",++c);
		printf("Total explored area: %.2lf\n\n",Sum);
	}
}