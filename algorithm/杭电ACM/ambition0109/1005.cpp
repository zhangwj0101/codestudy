////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-07 15:59:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    int num[50],a,b,n,k,i;
    while(scanf("%d %d %d",&a,&b,&n),a||b||n)
    {
        num[1]=1, num[2]=1;
        for(i=3;i<=49;i++)
        {
             num[i]=(a*num[i-1]+b*num[i-2])%7;
             if(num[i]==num[2] && num[i-1]==num[1])
                 break;
        }
        k=i-2;
        n=n%k;
        if(n==0)
            n=k;
        printf("%d\n",num[n]);
    }
}