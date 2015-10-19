////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-19 18:12:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2095
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int num,n,result,i;
    while(scanf("%d",&n),n){
        result=0;
        for(i=0;i<n;++i){
            scanf("%d",&num);
            result^=num;
        }
        printf("%d\n",result);
    }
    return 0;
}