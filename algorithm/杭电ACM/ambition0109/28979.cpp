////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-09 12:37:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2897
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:172KB
//////////////////System Comment End//////////////////
#include<stdio.h>

int main()
{
    unsigned short n,m,q;
    while(scanf("%hu%hu%hu",&q,&n,&m)!=EOF){
        q=(q-1)%(n+m)+1;
		puts(q<=n?"LOST":"WIN");
    }
}