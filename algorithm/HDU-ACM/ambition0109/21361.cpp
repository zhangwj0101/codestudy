////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-02 21:48:13
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
    int n,m,i=2,j,k,max=0;
	for(i=2,max=1;i<1000001;i++)
	{
		if(!num[i])
		{
			for(k=1;k*i<1000001;k++)
				num[k*i]=max;
			max++;
		}
	}
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",num[n]);
}