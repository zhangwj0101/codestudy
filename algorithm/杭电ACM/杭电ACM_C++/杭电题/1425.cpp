////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 19:31:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1425
////Problem Title: 
////Run result: Accept
////Run time:968MS
////Run memory:3784KB
//////////////////System Comment End//////////////////
/*
1425 sort
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 2560 K

GUN C++
*/
//用hash的思想
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int nMax=1000001;
const int Max=500000;

int num[nMax];

int main()
{
    int t,n,i,j,m,max,loc;

    while(scanf("%d %d",&n,&m)==2)
    {
        memset(num,0,sizeof(num));
        max=-Max;
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            loc=Max+t;
            num[loc]++;
            if(t>max)   max=t;
        }
        loc=Max+max;
        i=m;
        for(j=loc;j>=0;j--)
        {
            while(num[j])
            {
                printf("%d",j-Max);
                if(--i)
                    printf(" ");
                else
                    break;
                num[j]--;
            }
            if(i==0)
                break;
        }
        printf("\n");
    }
    return 0;
}

