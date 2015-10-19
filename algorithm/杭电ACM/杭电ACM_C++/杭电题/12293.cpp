////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-17 11:05:10
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,b,k;
	int i;
	int trans[9]={1};
	for (i=1;i<8;i++)
		trans[i]=trans[i-1]*10;

	while (scanf("%d%d%d",&a,&b,&k),a||b)
	{
		printf("%d\n",((a-b)%trans[k])?a+b:-1);
	}
    return 0;
}