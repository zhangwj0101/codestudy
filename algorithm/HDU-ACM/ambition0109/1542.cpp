////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-05 12:25:09
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

struct Seg_Tree{
	int left,right;
	int cvr;
	double sum;
}STree[600];

struct Segment{
	double hight;
	double left,right;
	int side;
}Seg[205];

int n,m;
double Dis[205];
bool cmp(const Segment& a,const Segment& b){
	return a.hight<b.hight;
}

void Build(int left,int right,int idx){
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].cvr=0;
	STree[idx].sum=0;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Modify(int left,int right,int idx,int val){
	if(STree[idx].left==left&&STree[idx].right==right){
		STree[idx].cvr+=val;
		if(STree[idx].cvr){
			STree[idx].sum=Dis[STree[idx].right+1]-Dis[STree[idx].left];
		}else{
			if(STree[idx].left==STree[idx].right){
				STree[idx].sum=0;
			}else{
				STree[idx].sum=STree[idx<<1].sum+STree[idx<<1|1].sum;
			}
		}
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
	if(STree[idx].cvr){
		STree[idx].sum=Dis[STree[idx].right+1]-Dis[STree[idx].left];
	}else{
		//printf("--%d  %lf\n",idx,STree[idx].sum);
		STree[idx].sum=STree[idx<<1].sum+STree[idx<<1|1].sum;
		//printf("+-%d  %lf\n",idx,STree[idx].sum);
	}
}

int Find(double num){
	int top=m,bot=1;
	int mid=(top+bot)>>1;
	int ans=mid;
	while(bot<=top){
		if(Dis[mid]>=num){
			top=(ans=mid)-1;
		}else{
			bot=mid+1;
		}
		mid=(top+bot)>>1;
	}
	return ans;
}

int main()
{
	int Cas=0;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			double x1,x2,y1,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			Dis[(i<<1)+1]=Seg[i<<1].left=Seg[i<<1|1].left=x1;
			Dis[(i<<1)+2]=Seg[i<<1].right=Seg[i<<1|1].right=x2;
			Seg[i<<1].hight=y1;
			Seg[i<<1|1].hight=y2;
			Seg[i<<1].side=1;
			Seg[i<<1|1].side=-1;
		}
		sort(Seg,Seg+2*n,cmp);
		sort(Dis+1,Dis+2*n+1);
		m=1;
		for(int i=2;i<=2*n;i++){
			if(Dis[i]!=Dis[i-1]){
				Dis[++m]=Dis[i];
			}
		}
		Build(1,m,1);
		double Sum=0;
		for(int i=0;i<2*n-1;i++){
			int pl=Find(Seg[i].left);
			int pr=Find(Seg[i].right)-1;
			Modify(pl,pr,1,Seg[i].side);
			//printf("*-%lf  %lf\n",STree[1].sum,(Seg[i+1].hight-Seg[i].hight));
			Sum+=STree[1].sum*(Seg[i+1].hight-Seg[i].hight);
		}
		printf("Test case #%d\n",++Cas);
		printf("Total explored area: %.2lf\n\n",Sum);
	}
}