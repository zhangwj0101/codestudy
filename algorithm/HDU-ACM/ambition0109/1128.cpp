////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-15 17:36:24
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1128
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:4116KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int a[1000001]={0};
main()
{
    int i,j,sum=0;
    for(i=1;sum<1000000;i++)
    {
        j=i;
        for(sum=j;j;j/=10)
            sum+=j%10;
        a[sum]=1;
    }
	for(i=1;i<=1000000;i++)
		if(!a[i])
            printf("%d\n",i); 
}