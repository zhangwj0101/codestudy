////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-31 18:58:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1420
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,a,b,c;
    __int64 s;
    for(scanf("%d",&n);n>0;n--)
    {
        scanf("%d%d%d",&a,&b,&c);
		a%=c;
        for(i=0,s=1;i<b;i++)
		{s*=a;s%=c;}
		printf("%d\n",s%c);
    }
}