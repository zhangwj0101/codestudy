////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-12 14:06:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3016
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:6008KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline void scan_ud(int &num){
    char in;
    in=getchar();
    while(in<'0'||in>'9') in=getchar();
    num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
        num*=10,num+=in-'0';
    }
}

inline void scan_d(int &num){
    char in;bool IsN=false;
    in=getchar();
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
        num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
}

struct Seg_Tree{
    int left,right;
    int id;
}STree[300000];

struct Plank{
    int lid,rid;
    int left,right,val,hight;
}plank[100005];

bool cmp(const Plank& a,const Plank& b){
    return a.hight<b.hight;
}

void Build(int left,int right,int idx){
    STree[idx].left=left;
    STree[idx].right=right;
    STree[idx].id=-1;
    if(left==right) return;
    int mid=(left+right)>>1;
    Build(left,mid,idx<<1);
    Build(mid+1,right,idx<<1|1);
}

void Modify(int left,int right,int val,int idx){
    if(STree[idx].left==left&&STree[idx].right==right){
        STree[idx].id=val;
        return;
    }
    if(STree[idx].id!=-1){
        STree[idx<<1].id=STree[idx<<1|1].id=STree[idx].id;
        STree[idx].id=-1;
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
}

int Query(int Pos,int idx){
    if(STree[idx].id!=-1){
        return STree[idx].id;
    }
    if(STree[idx].right==STree[idx].left){
        return STree[idx].id;
    }
    int mid=(STree[idx].left+STree[idx].right)>>1;
    if(Pos<=mid){
        return Query(Pos,idx<<1);
    }else{
        return Query(Pos,idx<<1|1);
    }
}

int Val[100005];
int main()
{
    int n;
    Build(1,100000,1);
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scan_ud(plank[i].hight);
            scan_ud(plank[i].left);
            scan_ud(plank[i].right);
            scan_d(plank[i].val);
        }
        sort(plank+1,plank+n+1,cmp);
        Modify(1,100000,0,1);
        for(int i=1;i<=n;i++){
            plank[i].lid=Query(plank[i].left,1);
            plank[i].rid=Query(plank[i].right,1);
            Modify(plank[i].left,plank[i].right,i,1);
        }
        memset(Val,0,sizeof(int)*n);
        Val[n]=100+plank[n].val;
        int Mval=-1;
        for(int i=n;i>0;i--){
            if(plank[i].lid!=0){
                if(Val[plank[i].lid]<Val[i]+plank[plank[i].lid].val){
                    Val[plank[i].lid]=Val[i]+plank[plank[i].lid].val;
                }
            }else if(Val[i]>Mval){
                Mval=Val[i];
            }
            if(plank[i].rid!=0){
                if(Val[plank[i].rid]<Val[i]+plank[plank[i].rid].val){
                    Val[plank[i].rid]=Val[i]+plank[plank[i].rid].val;
                }
            }else if(Val[i]>Mval){
                Mval=Val[i];
            }
        }
        if(Mval<=0) puts("-1");
        else printf("%d\n",Mval);
    }
}
