////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-08 21:12:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1406
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
bool f(int n)
{
    int i,s=1;
    for(i=2;i<sqrt(1.0*n);i++)
    {
        if(n%i==0)
            s+=n/i+i;
    }
    if(i*i==n)
        s+=i;
    return s==n;
}

int main()
{
    int i,j,n,k,n1,n2;
    cin>>n;
    for(i=0;i<n;i++)
    {
        k=0;
        cin>>n1>>n2;
		if(n1>n2)
			swap(n1,n2);
        for(j=n1;j<=n2;j++)
            if(f(j))
                k++;
        cout<<k<<endl;

    }
   return 0;
}