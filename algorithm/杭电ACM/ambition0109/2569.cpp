////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 14:54:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2569
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
    int n,m,i=1;
    __int64 num[40][2];
	num[0][0]=0;num[0][1]=3;
    for(scanf("%d",&n);n>0;n--)
    {
		for(scanf("%d",&m);i<m;i++)
		{
			num[i][0]=num[i-1][0]+num[i-1][1]*2;
			num[i][1]=num[i-1][0]+num[i-1][1];
		}
		printf("%I64d\n",num[m-1][0]+num[m-1][1]);
    }
}