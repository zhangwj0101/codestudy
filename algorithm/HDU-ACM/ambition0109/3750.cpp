////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-25 17:12:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3750
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;


int main(){
    int n;
    while(~scanf("%d",&n)){
        int Ans=0,t=0,tw=1;
        for(int i=1;;i++){
            for(int j=0;j<tw;j++){
                t++;
                if(t>n) break;
                Ans+=i;
            }
            if(t>n) break;
            tw*=2;
        }
        printf("%.2lf\n",double(Ans)/n);
    }
}