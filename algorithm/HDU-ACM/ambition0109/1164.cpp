////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-01 14:56:43
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1164
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int n,i,j,num[20];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=2,j=0;i<=n;i++)
        {
            if(!(n%i))
            {
				num[j]=i;
				j++;
				n/=i;
				i--;
            }
        }
		printf("%d",num[0]);
		for(i=1;i<j;i++)
			printf("*%d",num[i]);
		printf("\n");
    }
}