////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-25 12:39:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:368KB
//////////////////System Comment End//////////////////
/*
 * prim.cpp
 *
 *  Created on: 2010-11-25
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
//#include<queue>
using namespace std;
#define M 105
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

struct Edge{
    int lp,val,next;
    Edge(){}
    Edge(int _lp,int _val,int _next):
        lp(_lp),val(_val),next(_next){}
}E[999999];
int head[M],node;
void Init(){
    memset(head,-1,sizeof(head));
    node=0;
}

void Insert(int s,int v,int val){
    E[node]=Edge(v,val,head[s]);
    head[s]=node++;
}

bool Hash[M];
int que[999999],N;
int prim(int s){
    int t=1,MVal=0;
    que[0]=s;
    memset(Hash,false,sizeof(Hash));
    Hash[s]=true;
    while(t!=N){
        int Min=INF,cur=-1;
        for(int i=0;i<t;i++){
            for(int j=head[que[i]];j!=-1;j=E[j].next){
                if(Hash[E[j].lp]) continue;
                Min=MIN(Min,E[j].val);
                if(Min==E[j].val){
                    cur=j;
                }
            }
        }
        if(cur==-1) return -1;
        que[t++]=E[cur].lp;
        Hash[E[cur].lp]=true;
        MVal+=E[cur].val;
    }
    return MVal;
}

int main(){
    int n;
    while(scanf("%d",&n),n){
        Init();
        for(int i=0;i<n*(n-1)/2;i++){
            int u,v,val;
            scanf("%d%d%d",&u,&v,&val);
            Insert(u,v,val);
            Insert(v,u,val);
        }
        N=n;
        int Ans=prim(1);
        printf("%d\n",Ans);
    }
}
