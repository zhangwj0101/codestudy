////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-02 21:50:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2136
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:4120KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[1000001];
main()
{
    int n,i,k,max;
	for(i=2,max=1;i<1000001;i++)
	{
		if(num[i]) continue;
		for(k=1;k*i<1000001;k++)
			num[k*i]=max;
		max++;
	}
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",num[n]);
}