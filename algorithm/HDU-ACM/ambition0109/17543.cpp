////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-02 23:29:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:7128KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

inline void scan_ud(int &num)
{
	char in;
	in=getchar();
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
}

struct Node{
	int left,right;
	int max;
}STree[530000];

int num[200005];
void Build(int left,int right,int idx)
{
	STree[idx].left=left;
	STree[idx].right=right;
	if(left==right){
		STree[idx].max=num[left];
		return;
	}
	int mid=(left+right)>>1;
	Build(left,mid,idx<<1);
	Build(mid+1,right,idx<<1|1);
	if(STree[idx<<1].max>STree[idx<<1|1].max){
		STree[idx].max=STree[idx<<1].max;
	}else{
		STree[idx].max=STree[idx<<1|1].max;
	}
}

void Modify(int site,int idx,int num){
	if(STree[idx].left==STree[idx].right){
		STree[idx].max=num;
		return;
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(site<=mid){
		Modify(site,idx<<1,num);
	}else if(mid<site){
		Modify(site,idx<<1|1,num);
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

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			scan_ud(num[i]);
		}
		Build(1,n,1);
		for(int i=0;i<m;i++){
			char cmd[2];
			scanf("%s",cmd);
			if(cmd[0]=='U'){
				int id,score;
				scan_ud(id);
				scan_ud(score);
				Modify(id,1,score);
			}else if(cmd[0]=='Q'){
				int l,r;
				scan_ud(l);
				scan_ud(r);
				printf("%d\n",query(l,r,1));
			}
		}
	}
}