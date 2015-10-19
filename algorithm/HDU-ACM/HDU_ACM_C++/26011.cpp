////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-03-28 12:10:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2601
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:328KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
char hash[100001];
int pri[10000];
void main()
{
    int T,sum,k,count,j,p,i;
    __int64 n;

    for(i=2,p=0;i<=100000;i++)
    {
        if(hash[i]!=1)
		{
            pri[p++]=i;
			for(j=i+i;j<=100000;j+=i)
				hash[j]=1;
		}
    }

    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
		n++;
        k=(int)sqrt(1.0*n);
        sum=1;
        for(i=0;i<p&&pri[i]<=k;i++)
        {
            count=1;
            while(n%pri[i]==0)
            {
                count++;
                n/=pri[i];
                k=(int)sqrt(1.0*n);
            }
            sum*=count;
        }
        if(n!=1)
            sum*=2;

        sum-=2;
        printf("%d\n",(sum+1)/2);
    }
}