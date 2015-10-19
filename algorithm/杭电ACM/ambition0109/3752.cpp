////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-25 17:13:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3752
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if((n&1)==0){
            if(n>=(m*2)){
                puts("YES");
            }else{
                puts("NO");
            }
        }else{
            puts("NO");
        }
    }
}
