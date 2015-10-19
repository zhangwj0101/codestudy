////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-11 20:56:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1828
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:396KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

struct Seg_Tree{
	int left,right;
	bool ledge,redge;
	int cnt,len,edge;
}STree[30000];

struct Seg{
	int left,right;
	int hight,side;
}seg[10005];

int Abs(int a){
	int temp=a>>31;
	return (a+temp)^temp;
}

int Dis[10005];
bool cmp(const Seg& a,const Seg& b){
	return a.hight<b.hight;
}

void Build(int left,int right,int idx){
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].cnt=STree[idx].len=STree[idx].edge=0;
	STree[idx].ledge=STree[idx].redge=false;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Update(int idx){
	if(STree[idx].cnt){
		STree[idx].ledge=STree[idx].redge=true;
		STree[idx].len=Dis[STree[idx].right+1]-Dis[STree[idx].left];
		STree[idx].edge=2;
	}else{
		if(STree[idx].left==STree[idx].right){
			STree[idx].ledge=STree[idx].redge=false;
			STree[idx].edge=0;
			STree[idx].len=0;
		}else{
			STree[idx].ledge=STree[idx<<1].ledge;
			STree[idx].redge=STree[idx<<1|1].redge;
			STree[idx].len=STree[idx<<1].len+STree[idx<<1|1].len;
			STree[idx].edge=STree[idx<<1].edge+STree[idx<<1|1].edge
				-((STree[idx<<1].redge&STree[idx<<1|1].ledge)<<1);
		}
	}
}
void Modify(int left,int right,int idx,int val){
	if(STree[idx].left==left&&STree[idx].right==right){
		STree[idx].cnt+=val;
		Update(idx);
		return;
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
	Update(idx);
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

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			Dis[i<<1]=seg[i<<1].left=seg[i<<1|1].left=x1;
			Dis[i<<1|1]=seg[i<<1].right=seg[i<<1|1].right=x2;
			seg[i<<1].hight=y1;
			seg[i<<1|1].hight=y2;
			seg[i<<1].side=-1;
			seg[i<<1|1].side=1;
		}
		sort(seg,seg+2*n,cmp);
		sort(Dis,Dis+2*n);
		int m=0;
		for(int i=1;i<2*n;i++){
			if(Dis[m]!=Dis[i]){
				Dis[++m]=Dis[i];
			}
		}
		Build(0,m,1);
		int Sum=0,temp=0;
		for(int i=0;i<2*n-1;i++){
			int pl=Find(seg[i].left,m);
			int pr=Find(seg[i].right,m)-1;
			Modify(pl,pr,1,seg[i].side);
			Sum+=STree[1].edge*(seg[i+1].hight-seg[i].hight);
			Sum+=Abs(STree[1].len-temp);
			temp=STree[1].len;
		}
		Sum+=temp;
		printf("%d\n",Sum);
	}
}
