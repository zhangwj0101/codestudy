////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 13:22:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2492
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:1568KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))

int Inc[100010],Dec[100010];
int N=100000;
void Modify(int Index[],int Pos,int Val){
    for(int i=Pos;i<=N;i+=Lowbit(i)){
        Index[i]+=Val;
    }
}

int Query(int Index[],int t){
    int result=0;
    for(int i=t;i>0;i-=Lowbit(i)){
        result+=Index[i];
    }
    return result;
}

int num[20010],Hash[100010];
int Incn[20010],Decn[20010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        memset(Hash,0,sizeof(Hash));
        memset(Inc,0,sizeof(Inc));
        memset(Dec,0,sizeof(Dec));
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
            Hash[num[i]]++;
            Incn[i]=Query(Inc,num[i]);
            Decn[i]=Query(Dec,100001-num[i]);
            Modify(Inc,num[i],1);
            Modify(Dec,100001-num[i],1);
//            printf("##%d %d\n",Incn[i],Decn[i]);
        }
        memset(Inc,0,sizeof(Inc));
        memset(Dec,0,sizeof(Dec));
        long long Sum=0;
        for(int i=n-1;i>=0;i--){
            int tInc=Query(Inc,num[i]);
            int tDec=Query(Dec,100001-num[i]);
            Modify(Inc,num[i],1);
            Modify(Dec,100001-num[i],1);
//            printf("**%d %d\n",tInc,tDec);
            Sum+=Incn[i]*tDec+Decn[i]*tInc;
        }
        sort(num,num+n);
        if(Hash[num[0]]>=3){
            Sum-=((long long)(Hash[num[0]]*(Hash[num[0]]-1))/2*(Hash[num[0]]-2)/3);
        }
        for(int i=1;i<n;i++){
            if(num[i-1]!=num[i]&&Hash[num[i]]>=3){
                Sum-=((long long)(Hash[num[i]]*(Hash[num[i]]-1))/2*(Hash[num[i]]-2)/3);
            }
        }
        printf("%I64d\n",Sum);
    }
}

