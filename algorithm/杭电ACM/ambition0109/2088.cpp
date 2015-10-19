////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-08 17:21:21
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int n,i,num[50],sum,aver,t=0;
    while(scanf("%d",&n),n)
    {
		if(t)
			printf("\n");
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        aver=sum/n;
        for(i=0,sum=0;i<n;i++)
            if(num[i]>aver)
                sum+=num[i]-aver;
        printf("%d\n",sum);
		t=1;
    }
}