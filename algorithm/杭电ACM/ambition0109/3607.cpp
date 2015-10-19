////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-07 18:13:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3607
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:4868KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

struct Step{
	int high,gold;
}step[100001];

struct Node{
	int left,right;
	int max;
}STree[300000];
int Dis[100001];
int All[100001];

void Build(int left,int right,int idx)
{
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].max=0;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Modify(int Pos,int idx,int num){
	if(STree[idx].left==STree[idx].right){
		STree[idx].max=num;
		return;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(Pos<=mid){
		Modify(Pos,idx<<1,num);
	}else if(mid<Pos){
		Modify(Pos,idx<<1|1,num);
	}
	if(STree[idx<<1].max>STree[idx<<1|1].max){
		STree[idx].max=STree[idx<<1].max;
	}else{
		STree[idx].max=STree[idx<<1|1].max;
	}
}

int query(int left,int right,int idx)
{
	if(STree[idx].left==left&&STree[idx].right==right){
		return STree[idx].max;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(right<=mid){
		return query(left,right,idx<<1);
	}else if(left>mid){
		return query(left,right,idx<<1|1);
	}else{
		int ml=query(left,mid,idx<<1);
		int mr=query(mid+1,right,idx<<1|1);
		return (ml>mr?ml:mr);
	}
}

int Find(int val,int m){
	int top=0,bot=m;
	int mid=(top+bot)>>1;
	while(1){
		if(Dis[mid]==val){
			return mid;
		}
		if(Dis[mid]<val){
			top=mid+1;
		}else{
			bot=mid-1;
		}
		mid=(top+bot)>>1;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(All,0,sizeof(All));
		for(int i=0;i<n;i++){
			scanf("%d%d",&step[i].high,&step[i].gold);
			Dis[i]=step[i].high;
		}
		int m=0;
		for(int i=1;i<n;i++){
			if(Dis[i]!=Dis[i-1]){
				Dis[++m]=Dis[i];
			}
		}
		sort(Dis,Dis+m+1);
		Build(0,m,1);
		for(int i=0;i<n;i++){
			int p=Find(step[i].high,m);
			if(p==0){
				if(All[p]<step[i].gold){
					All[p]=step[i].gold;
					Modify(p,1,All[p]);
				}
				continue;
			}
			int tm=query(0,p-1,1);
			if(All[p]<tm+step[i].gold){
				All[p]=tm+step[i].gold;
				Modify(p,1,All[p]);
			}
		}
		printf("%d\n",query(0,m,1));
	}
}