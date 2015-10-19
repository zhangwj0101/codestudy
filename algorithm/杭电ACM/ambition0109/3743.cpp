////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-19 21:53:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3743
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:4928KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))

int Idx[1000005],N;
void Modify(int Pos,int Val){
    for(int i=Pos;i<=N;i+=Lowbit(i)){
        Idx[i]+=Val;
    }
}

int Query(int Pos){
    int result=0;
    for(int i=Pos;i>0;i-=Lowbit(i)){
        result+=Idx[i];
    }
    return result;
}

int Num[1000005],dis[1000005];
int Find(int x,int m){
    int top=0,bot=m;
    int mid=(top+bot)>>1;
    while(true){
        if(dis[mid]==x) return mid;
        if(dis[mid]<x){
            top=mid+1;
        }else if(dis[mid]>x){
            bot=mid-1;
        }
        mid=(top+bot)>>1;
    }
}

int main(){
    int n;N=1000001;
    while(~scanf("%d",&n)){
        
        for(int i=0;i<n;i++){
            scanf("%d",&Num[i]);
            dis[i]=Num[i];
        }
        sort(dis,dis+n);
        long long Ans=0;
        memset(Idx,0,sizeof(Idx));
        for(int i=0;i<n;i++){
            int pos=1000001-Find(Num[i],n);
            Ans+=Query(pos);
            Modify(pos,1);
        }
        printf("%I64d\n",Ans);
    }
}