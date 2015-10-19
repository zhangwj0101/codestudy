////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-08 20:54:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int fun(int n)
{
    int i=1;
    while(n!=1)
    {
        if(n%2==1)
            n=3*n+1;
        else
            n/=2;
        i++;
    }
    return i;
}
int main()
{
    int a,b,i,t,m;
    while(cin>>a>>b)
    {
        m=0;
        cout<<a<<" "<<b<<" ";
		if(a>b)
			swap(a,b);
        for(i=a;i<=b;i++)
        {
            t=fun(i);
            if(m<t)
                m=t;
        }
        cout<<m<<endl;

    }
    return 0;
}