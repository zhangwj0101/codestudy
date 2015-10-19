////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-19 21:54:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3742
////Problem Title: 
////Run result: Accept
////Run time:1250MS
////Run memory:12356KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Edge{
    int u,v,c;
}E[5999999];

bool cmp(const Edge& a,const Edge& b){
    return a.c<b.c;
}

int Idx[1000005];
int Find(int x){
    if(Idx[x]==x) return x;
    return Idx[x]=Find(Idx[x]);
}

bool Union(int x,int y){
    int rx=Find(x);
    int ry=Find(y);
    if(rx==ry) return false;
    Idx[rx]=ry;
    return true;
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<n;i++) Idx[i]=i;
        for(int i=0;i<m;i++){
            int u,v,c;
            scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].c);
        }
        sort(E,E+m,cmp);
        int cnt=0,Max;
        for(int i=0;i<m;i++){
            if(Union(E[i].u,E[i].v)){
                cnt++;
                Max=E[i].c;
            }
            if(cnt==n-1) break;
        }
        if(cnt==n-1){
            printf("%d\n",Max);
        }else{
            puts("IMPOSSIBLE");
        }
    }
}