////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-09 12:33:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2897
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main()
{
    unsigned short n,m,q;
    while(scanf("%hu%hu%hu",&q,&n,&m)!=EOF){
        q=(q-1)%(n+m)+1;
		if(q<=n) printf("LOST\n");
        else printf("WIN\n");
    }
}