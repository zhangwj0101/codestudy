////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-20 18:49:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

bool dp[10005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,min=0;
        scanf("%d",&n);
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<=n;i++){
            if(dp[i]){
                if(i>min) min=i;
                dp[i+150]=true;
                dp[i+200]=true;
                dp[i+350]=true;
            }
        }
        printf("%d\n",n-min);
    }
}