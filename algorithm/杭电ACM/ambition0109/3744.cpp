////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-25 17:07:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3744
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
    int mm,r;
    friend bool operator< (const Node& a,const Node& b){
        return a.r>b.r;
    }
}NN[105];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d%d",&NN[i].mm,&NN[i].r);
        }
        sort(NN,NN+n);
        bool flag=true;
        int Max=0;
        for(int i=0;i<n;i++){
            if(NN[i].mm>Max){
                Max=NN[i].mm;
            }else{
                NN[i].mm+=400;
                if(NN[i].mm>m){
                    flag=false;
                    break;
                }
                i--;
            }
        }
        puts(flag?"YES":"NO");
    }
}