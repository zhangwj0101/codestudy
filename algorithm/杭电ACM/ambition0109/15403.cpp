////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-08 15:57:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1540
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:2796KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

struct Seg_Tree{
	int left,right;
	int acvr,lcvr,rcvr;
	int Seglen(){
		return right-left+1;
	}
}STree[150000];

int Max(int a,int b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

void Build(int left,int right,int idx){
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].acvr=STree[idx].Seglen();
	STree[idx].lcvr=STree[idx].rcvr=STree[idx].acvr;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Modify(int Pos,int val,int idx){
	if(STree[idx].left==STree[idx].right){
		STree[idx].acvr=STree[idx].lcvr=STree[idx].rcvr=val;
		return;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(Pos<=mid){
		Modify(Pos,val,idx<<1);
	}else{
		Modify(Pos,val,idx<<1|1);
	}
	STree[idx].acvr=Max(STree[idx<<1].acvr,STree[idx<<1|1].acvr);
	STree[idx].acvr=Max(STree[idx<<1].rcvr+STree[idx<<1|1].lcvr,STree[idx].acvr);
	STree[idx].lcvr=STree[idx<<1].lcvr;
	STree[idx].rcvr=STree[idx<<1|1].rcvr;
	if(STree[idx<<1].acvr==STree[idx<<1].Seglen()){
		STree[idx].lcvr+=STree[idx<<1|1].lcvr;
	}
	if(STree[idx<<1|1].acvr==STree[idx<<1|1].Seglen()){
		STree[idx].rcvr+=STree[idx<<1].rcvr;
	}
}

int Query(int Pos,int idx){
	if(STree[idx].left==STree[idx].right){
		return STree[idx].acvr;
	}
	if(STree[idx].acvr==STree[idx].Seglen()){
		return STree[idx].acvr;
	}
	if(STree[idx].acvr==0){
		return 0;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(Pos<=mid){
		if(STree[idx<<1].right-STree[idx<<1].rcvr<Pos){
			return Query(Pos,idx<<1)+STree[idx<<1|1].lcvr;
		}else {
			if(STree[idx<<1].left+STree[idx<<1].lcvr>Pos){
				return STree[idx<<1].lcvr;
			}
			return Query(Pos,idx<<1);
		}
	}else{
		if(STree[idx<<1|1].left+STree[idx<<1|1].lcvr>Pos){
			return Query(Pos,idx<<1|1)+STree[idx<<1].rcvr;
		}else{
			if(STree[idx<<1|1].right-STree[idx<<1|1].rcvr<Pos){
				return STree[idx<<1|1].rcvr;
			}
			return Query(Pos,idx<<1|1);
		}
	}
}
int Dis[50010];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		Build(1,n,1);
		int t=-1;
		while(m--){
			char cmd[2];
			scanf("%s",cmd);
			if(cmd[0]=='D'){
				int p;
				scanf("%d",&p);
				Dis[++t]=p;
				Modify(p,0,1);
			}else if(cmd[0]=='R'){
				if(t==-1) continue;
				int p=Dis[t--];
				Modify(p,1,1);
			}else if(cmd[0]=='Q'){
				int p;
				scanf("%d",&p);
				printf("%d\n",Query(p,1));
			}
		}
	}
}