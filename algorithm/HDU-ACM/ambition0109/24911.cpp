////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 18:56:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2491
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:936KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

struct Unit{
    int s,t;
}unit[100010];

bool cmp(const Unit& a,const Unit& b){
    return ((__int64)a.s+a.t)<((__int64)b.s+b.t);
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