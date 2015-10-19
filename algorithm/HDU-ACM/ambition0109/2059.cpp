////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-23 14:33:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2059
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int Max(const int& a,const int& b){
    int dif=b-a;
    return b-(dif&(dif>>31));
}
int Min(const int& a,const int& b){
    int dif=b-a;
    return a+(dif&(dif>>31));
}

int p[105];
double time[105];
int main(){
    int l;
    while(~scanf("%d",&l)){
        int n,c,t,vr,vt1,vt2;
        scanf("%d%d%d",&n,&c,&t);
        scanf("%d%d%d",&vr,&vt1,&vt2);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
            time[i]=Max(p[i]-c,0)*1.0/vt2+Min(p[i],c)*1.0/vt1;
            for(int j=1;j<i;j++){
                double ttime=time[j]+(Max(p[i]-c,p[j])-p[j])*1.0/vt2+Min(p[i]-p[j],c)*1.0/vt1+t;
                if(time[i]>ttime){
                    time[i]=ttime;
                }
            }
        }
        time[n+1]=Max(l-c,0)*1.0/vt2+Min(l,c)*1.0/vt1;
        for(int j=1;j<=n;j++){
            double ttime=time[j]+(Max(l-c,p[j])-p[j])*1.0/vt2+Min(l-p[j],c)*1.0/vt1+t;
            if(time[n+1]>ttime){
                time[n+1]=ttime;
            }
        }
        puts(time[n+1]<(l*1.0/vr)?"What a pity rabbit!":"Good job,rabbit!");
    }
}
