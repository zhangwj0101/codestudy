////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-01 09:51:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1866
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node{
	int left,right,cvr;
	int len;
}STree[3000];

struct Seg{
	int left,right,hight;
	int side;
}seg[305];

int Max(const int& a,const int& b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}
int Min(const int& a,const int& b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

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
		STree[idx].len=STree[idx].right-STree[idx].left;
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

char str[1100];
int main(){
	while(scanf("%[^+\n]",str)!=EOF){
		Build(0,1000,1);
		int x1,x2,y1,y2,t=0;
		sscanf(str,"%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d",&x1,&y1,&x2,&y2);
		seg[0].left=seg[1].left=Min(x1,x2);
		seg[0].right=seg[1].right=Max(x1,x2);
		seg[0].hight=Min(y1,y2); seg[0].side=1;
		seg[1].hight=Max(y1,y2); seg[1].side=-1;
		for(int i=1;getchar()!='\n';i++){
			scanf("%[^+\n]",str);
			sscanf(str,"%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d",&x1,&y1,&x2,&y2);
			seg[i<<1].left=seg[i<<1|1].left=Min(x1,x2);
			seg[i<<1].right=seg[i<<1|1].right=Max(x1,x2);
			seg[i<<1].hight=Min(y1,y2); seg[i<<1].side=1;
			seg[i<<1|1].hight=Max(y1,y2); seg[i<<1|1].side=-1;
			t=i;
		}
		t++;
		sort(seg,seg+t*2,cmp);
		int Sum=0;
		for(int i=0;i<t*2-1;i++){
			if(seg[i].left!=seg[i].right){
				Modify(seg[i].left,seg[i].right,seg[i].side,1);
			}
			Sum+=STree[1].len*(seg[i+1].hight-seg[i].hight);
		}
		printf("%d\n",Sum);
	}
}
