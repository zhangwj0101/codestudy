////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 18:56:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2491
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:936KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

struct Unit{
    int s,t;
}unit[100010];

bool cmp(const Unit& a,const Unit& b){
    return ((long long)a.s+a.t)<((long long)b.s+b.t);
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            scanf("%d%d",&unit[i].s,&unit[i].t);
        }
        sort(unit,unit+n,cmp);
        int start=unit[0].s;
        int i;
        for(i=0;i<n;i++){
            if(start<unit[i].s){
                start=unit[i].s;
            }
            start+=(unit[i].t-unit[i].s)/2+1;
            if(start>unit[i].t){
                break;
            }
        }
        puts(i==n?"YES":"NO");
    }
}