////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-06 20:47:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1255
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:412KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

struct Seg_Tree{
	int left,right;
	double one;
	double more;
	int cvr;
}STree[6000];

struct Seg{
	double left,right,hight;
	int side;
}seg[2010];

inline void scan_uf(double &num)
{
    char in;double Dec=0.1;
    bool IsD=false;
    in=getchar();
    while(in!='.'&&(in<'0'||in>'9'))
        in=getchar();
    if(in=='.') {IsD=true;num=0;}
    else num=in-'0';
    if(!IsD){
        while(in=getchar(),in>='0'&&in<='9'){
            num*=10;num+=in-'0';}
    }
    if(in=='.'){
        while(in=getchar(),in>='0'&&in<='9'){
            num+=Dec*(in-'0');Dec*=0.1;
        }
    }
}

bool cmp(const Seg& a,const Seg& b){
	return a.hight<b.hight;
}
double Pos[2010];
void Build(int left,int right,int idx){
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].one=0;
	STree[idx].more=0;
	STree[idx].cvr=0;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Update(int idx){
	if(STree[idx].cvr==0){
		if(STree[idx].left==STree[idx].right){
			STree[idx].more=0;
			STree[idx].one=0;
		}else{
			STree[idx].one=STree[idx<<1].one+STree[idx<<1|1].one;
			STree[idx].more=STree[idx<<1].more+STree[idx<<1|1].more;
		}
	}else if(STree[idx].cvr==1){
		STree[idx].one=Pos[STree[idx].right+1]-Pos[STree[idx].left];
		if(STree[idx].left==STree[idx].right){
			STree[idx].more=0;
		}else{
			STree[idx].more=STree[idx<<1].one+STree[idx<<1|1].one;
		}
	}else{
		STree[idx].more=STree[idx].one=
			Pos[STree[idx].right+1]-Pos[STree[idx].left];
	}
}

void Modify(int left,int right,int idx,int val){
	if(STree[idx].left==left&&STree[idx].right==right){
		STree[idx].cvr+=val;
		Update(idx);
		return;
	}
	int mid=(STree[idx].right+STree[idx].left)>>1;
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

int Find(double val,int Max){
	int top=0,bot=Max;
	int mid=(top+bot)>>1;
	while(1){
		if(Pos[mid]==val){
			return mid;
		}else if(Pos[mid]<val){
			top=mid+1;
		}else{
			bot=mid-1;
		}
		mid=(top+bot)>>1;
	}
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			double x1,x2,y1,y2;
			scan_uf(x1);
			scan_uf(y1);
			scan_uf(x2);
			scan_uf(y2);
			Pos[i<<1]=seg[i<<1].left=seg[i<<1|1].left=x1;
			Pos[i<<1|1]=seg[i<<1].right=seg[i<<1|1].right=x2;
			seg[i<<1].hight=y1;
			seg[i<<1|1].hight=y2;
			seg[i<<1].side=1;
			seg[i<<1|1].side=-1;
		}
		sort(Pos,Pos+2*n);
		sort(seg,seg+2*n,cmp);
		int m=1;
		for(int i=1;i<2*n;i++){
			if(Pos[i]!=Pos[i-1]){
				Pos[m++]=Pos[i];
			}
		}
		Build(0,m,1);
		double Sum=0;
		for(int i=0;i<2*n-1;i++){
			int pl=Find(seg[i].left,m);
			int pr=Find(seg[i].right,m);
			Modify(pl,pr-1,1,seg[i].side);
			Sum+=STree[1].more*(seg[i+1].hight-seg[i].hight);
		}
		printf("%.2lf\n",Sum);
	}
}