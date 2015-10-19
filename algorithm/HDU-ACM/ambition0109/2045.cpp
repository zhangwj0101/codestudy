////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-18 14:05:21
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int n,i;
	__int64 num[3];
    while(scanf("%d",&n)!=EOF)
    {
		if(n==1)
			num[0]=3;
		else if(n==2)
			num[0]=6;
		else if(n==3)
			num[0]=6;
		else
			for(num[0]=6,num[1]=6,i=2;i<n;i++)
			{
			  num[2]=num[1]+2*num[0];
			  num[0]=num[1];
			  num[1]=num[2];
			}
        printf("%I64d\n",num[0]);
    }
}