////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-06 13:15:40
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1850
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int num[100];
main()
{
    int m,i,xor,t,count;
    while(scanf("%d",&m),m)
    {
        for(count=0,i=0,xor=0;i<m;i++)
        {
            scanf("%d",&num[i]);
            xor=xor^num[i];
        }
        if(xor)
        {
			for(t=0;xor!=1;t++) xor>>=1;
            for(i=0;i<m;i++)
			{
				num[i]>>=t;
				if(num[i]%2) count++;
            }
        }
		printf("%d\n",count);
    }
}