////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-27 17:38:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

void main()
{
    int m,n,mm,nn,i,j,t,q;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
		mm=m>n?n:m; nn=m>n?m:n;
        for(i=mm,q=0;i<=nn;i++)
        {
            for(j=i,t=1;j>1;t++)
            {
                if(j%2==0)
                    j/=2;
                else
                    j=j*3+1;
            }
            if(t>q)
                q=t;
        }
        printf("%d %d %d\n",m,n,q);
    }
}