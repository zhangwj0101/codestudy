////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-31 19:27:44
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2153
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int n,m,i;
    while(scanf("%d",&n)!=EOF)
    {
		if(n==0)
			continue;
        else if(n==1)
            printf("%3d\n",1);
        else
        {
            for(i=0;i<n;i++)
                printf("%3d",i+1);
            printf("\n");
            for(i=0;i<n-2;i++)
            {
                printf("%3d",4*n-4-i);
                for(m=0;m<n-2;m++)
                    printf("%3c",' ');
                printf("%3d\n",n+i+1);
            }
            for(i=0;i<n;i++)
                printf("%3d",4*n-n-2-i);
            printf("\n");
        }
    }
}