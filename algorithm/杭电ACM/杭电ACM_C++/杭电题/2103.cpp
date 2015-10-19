////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-14 10:17:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2103
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
    int k,m,n,i,a[31],j;
    while(cin>>k)
    {
        while(k--)
        {
            __int64 sum=0;
            cin>>m>>n;
            for(i=0;i<n;i++)
                cin>>a[i];
            int k=1;
            for(i=0;i<n;i++)
            {
                if(a[i]==1&& i<m)
                {
                    j=n-1-i;
                    sum+=(1<<j)-1;k=0;
                    break;
                }
            }
            if(k){
            if(n>=m)
            {
                j=n-m;sum+=(1<<j)-1;
            }
            }
			printf(sum?"%I64d0000":"0",sum);
			puts(" RMB");
        }
    }
    return 0;
}