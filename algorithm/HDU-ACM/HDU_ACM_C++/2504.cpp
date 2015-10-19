////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-23 14:17:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2504
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int gcd(int m,int n)
{
    int temp;
    while(temp=m%n)
    {
        m=n;
        n=temp;
    }
    return n;
}

int main()
{
    int n;
    while(cin>>n)
    {
        while(n--)
        {
            _int64 a,b,c,p,i;
            scanf("%I64d %I64d",&a,&b);
            p=a/b;
            for(i=2;gcd(p,i)!=1;i++);
            c=i*b;
            printf("%I64d\n",c);    
        }
    }
    return 0;
}