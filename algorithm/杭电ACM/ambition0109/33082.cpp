////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 14:30:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3308
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:8828KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define M 100005

struct Seg{
	int l,r,len;
	int lv,rv;
	int ll,rl,tl;
}seg[M*3];
int val[M];

void update(int idx){
	seg[idx].lv=seg[idx<<1].lv;
	seg[idx].rv=seg[idx<<1|1].rv;
	
	seg[idx].tl=MAX(seg[idx<<1].tl,seg[idx<<1|1].tl);
	if(seg[idx<<1].rv<seg[idx<<1|1].lv){
		seg[idx].tl=MAX(seg[idx].tl,(seg[idx<<1].rl+seg[idx<<1|1].ll));
	}
	
	seg[idx].ll=seg[idx<<1].ll;
	seg[idx].rl=seg[idx<<1|1].rl;
	if(seg[idx<<1].rv<seg[idx<<1|1].lv){
		if(seg[idx<<1].ll==seg[idx<<1].len){
			seg[idx].ll=seg[idx<<1].len+seg[idx<<1|1].ll;
		}
		if(seg[idx<<1|1].rl==seg[idx<<1|1].len){
			seg[idx].rl=seg[idx<<1|1].len+seg[idx<<1].rl;
		}
	}
}

void build(int l,int r,int idx){
	seg[idx].l=l;
	seg[idx].r=r;
	seg[idx].len=r-l+1;
	seg[idx].lv=val[l];
	seg[idx].rv=val[r];
	if(l==r){
		seg[idx].tl=1;
		seg[idx].ll=1;
		seg[idx].rl=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,idx<<1);
	build(mid+1,r,idx<<1|1);
	
	update(idx);
}

void modify(int pos,int val,int idx){
	if(seg[idx].l==pos&&seg[idx].r==pos){
		seg[idx].lv=seg[idx].rv=val;
		return;
	}
	int mid=(seg[idx].l+seg[idx].r)>>1;
	if(pos<=mid){
		modify(pos,val,idx<<1);
	}else if(pos>mid){
		modify(pos,val,idx<<1|1);
	}
	
	update(idx);
}

int query(int l,int r,int idx){
	if(seg[idx].l==l&&seg[idx].r==r){
		return seg[idx].tl;
	}
	int mid=(seg[idx].l+seg[idx].r)>>1;
	if(r<=mid){
		return query(l,r,idx<<1);
	}else if(l>mid){
		return query(l,r,idx<<1|1);
	}else{
		int tll=query(l,mid,idx<<1);
		int trl=query(mid+1,r,idx<<1|1);
		int ttl=MAX(tll,trl);
		if(seg[idx<<1].rv<seg[idx<<1|1].lv){
			int ttll=MIN(seg[idx<<1].rl,(mid-l+1));
			int ttlr=MIN(seg[idx<<1|1].ll,(r-mid));
			ttl=MAX(ttl,(ttll+ttlr));
		}
		return ttl;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&val[i]);
		}
		build(0,n-1,1);
		
		char cmd[5];
		for(int i=0;i<m;i++){
			scanf("%s",cmd);
			if(cmd[0]=='Q'){
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%d\n",query(l,r,1));
			}else if(cmd[0]=='U'){
				int p,v;
				scanf("%d%d",&p,&v);
				modify(p,v,1);
			}
		}
	}
}