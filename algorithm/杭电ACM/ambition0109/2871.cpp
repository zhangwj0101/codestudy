////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-08 20:35:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2871
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:3608KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

struct Seg_Tree{
	int left,right;
	int acvr,lcvr,rcvr;
	int cvr;
	int seglen(){
		return right-left+1;
	}
}STree[150000];

struct Block{
	int start,end;
	void set(int s,int e){
		start=s;
		end=e;
	}
};

int Max(int a,int b){
	int dif=b-a;
	return b-(dif&dif>>31);
}

void Build(int left,int right,int idx){
	STree[idx].left=left;
	STree[idx].right=right;
	STree[idx].cvr=-1;
	STree[idx].acvr=STree[idx].seglen();
	STree[idx].lcvr=STree[idx].rcvr=STree[idx].acvr;
	if(left==right) return;
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
}

void Modify(int left,int right,int val,int idx){
	if(STree[idx].left==left&&STree[idx].right==right){
		STree[idx].cvr=val;
		if(val){
			STree[idx].acvr=STree[idx].lcvr=STree[idx].rcvr=0;
		}else{
			STree[idx].acvr=STree[idx].seglen();
			STree[idx].lcvr=STree[idx].rcvr=STree[idx].acvr;
		}
		return;
	}
	if(STree[idx].cvr==0){
		STree[idx].cvr=-1;
		STree[idx<<1].cvr=STree[idx<<1|1].cvr=0;
		STree[idx<<1].acvr=STree[idx<<1].seglen();
		STree[idx<<1].rcvr=STree[idx<<1].lcvr=STree[idx<<1].acvr;
		STree[idx<<1|1].acvr=STree[idx<<1|1].seglen();
		STree[idx<<1|1].rcvr=STree[idx<<1|1].lcvr=STree[idx<<1|1].acvr;
	}else if(STree[idx].cvr==1){
		STree[idx].cvr=-1;
		STree[idx<<1].cvr=STree[idx<<1|1].cvr=1;
		STree[idx<<1].acvr=STree[idx<<1].rcvr=STree[idx<<1].lcvr=0;
		STree[idx<<1|1].acvr=STree[idx<<1|1].rcvr=STree[idx<<1|1].lcvr=0;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(right<=mid){
		Modify(left,right,val,idx<<1);
	}else if(left>mid){
		Modify(left,right,val,idx<<1|1);
	}else{
		Modify(left,mid,val,idx<<1);
		Modify(mid+1,right,val,idx<<1|1);
	}
	STree[idx].acvr=Max(STree[idx<<1].acvr,STree[idx<<1|1].acvr);
	STree[idx].acvr=Max(STree[idx].acvr,STree[idx<<1].rcvr+STree[idx<<1|1].lcvr);
	STree[idx].lcvr=STree[idx<<1].lcvr;
	STree[idx].rcvr=STree[idx<<1|1].rcvr;
	if(STree[idx<<1].acvr==STree[idx<<1].seglen()){
		STree[idx].lcvr+=STree[idx<<1|1].lcvr;
	}
	if(STree[idx<<1|1].acvr==STree[idx<<1|1].seglen()){
		STree[idx].rcvr+=STree[idx<<1].rcvr;
	}
}

int Query(int len,int idx){
	if(STree[idx].left==STree[idx].right){
		return STree[idx].left;
	}
	if(STree[idx].cvr==0){
		STree[idx].cvr=-1;
		STree[idx<<1].cvr=STree[idx<<1|1].cvr=0;
		STree[idx<<1].acvr=STree[idx<<1].seglen();
		STree[idx<<1].rcvr=STree[idx<<1].lcvr=STree[idx<<1].acvr;
		STree[idx<<1|1].acvr=STree[idx<<1|1].seglen();
		STree[idx<<1|1].rcvr=STree[idx<<1|1].lcvr=STree[idx<<1|1].acvr;
	}else if(STree[idx].cvr==1){
		STree[idx].cvr=-1;
		STree[idx<<1].cvr=STree[idx<<1|1].cvr=1;
		STree[idx<<1].acvr=STree[idx<<1].rcvr=STree[idx<<1].lcvr=0;
		STree[idx<<1|1].acvr=STree[idx<<1|1].rcvr=STree[idx<<1|1].lcvr=0;
	}
	if(STree[idx<<1].acvr>=len){
		return Query(len,idx<<1);
	}else if(STree[idx<<1].rcvr+STree[idx<<1|1].lcvr>=len){
		return STree[idx<<1].right-STree[idx<<1].rcvr+1;
	}else if(STree[idx<<1|1].acvr>=len){
		return Query(len,idx<<1|1);
	}else{
		return 0;
	}
}

vector<Block> Mem;
int Find(int val,int m){
	int top=0,bot=m;
	int mid=(top+bot)>>1;
	int ans=mid;
	while(top<=bot){
		if(Mem[mid].start<=val){
			top=(ans=mid)+1;
		}else{
			bot=mid-1;
		}
		mid=(top+bot)>>1;
	}
	return ans;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		Block t;
		t.set(0,0);
		Mem.clear();
		Mem.push_back(t);
		Build(1,n,1);
		while(m--){
			char cmd[10];
			scanf("%s",cmd);
			if(strcmp(cmd,"New")==0){
				int p;
				scanf("%d",&p);
				if(STree[1].acvr<p){
					puts("Reject New");
				}else{
					int s=Query(p,1);
					printf("New at %d\n",s);
					Modify(s,s+p-1,1,1);
					t.set(s,s+p-1);
					if(Mem.empty()){
						Mem.push_back(t);
					}else{
						int f=Find(s,Mem.size()-1);
						Mem.insert(Mem.begin()+f+1,t);
					}
				}
			}else if(strcmp(cmd,"Free")==0){
				int p;
				scanf("%d",&p);
				int f=Find(p,Mem.size()-1);
				if(f==0||Mem[f].end<p){
					puts("Reject Free");
				}else{
					printf("Free from %d to %d\n",Mem[f].start,Mem[f].end);
					Modify(Mem[f].start,Mem[f].end,0,1);
					Mem.erase(Mem.begin()+f);
				}
			}else if(strcmp(cmd,"Get")==0){
				int p;
				scanf("%d",&p);
				if(int(Mem.size())-1<p){
					puts("Reject Get");
				}else{
					printf("Get at %d\n",Mem[p].start);
				}
			}else if(strcmp(cmd,"Reset")==0){
				puts("Reset Now");
				Modify(1,n,0,1);
				Mem.clear();
				t.set(0,0);
				Mem.push_back(t);
			}
		}
		puts("");
	}
}