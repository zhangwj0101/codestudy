////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-15 10:24:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2897
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main()
{
	unsigned short n,m,q;
	while(scanf("%hd%hd%hd",&q,&n,&m)!=EOF)
	{
		q%=(n+m);
		if(q==0) printf("WIN\n");
		else if(q<=n) printf("LOST\n");
		else  printf("WIN\n");
	}
}