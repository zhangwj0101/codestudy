////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 21:17:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1597
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	__int64 t;
    int n,i,s,k;
    cin>>k;
    for(i=0;i<k;i++)
    {
		scanf("%d",&n);
		t=(__int64)sqrt(2.0*n);
        s=(t*t+t)/2;
        if(s<n)
            s=n-s;
        else
            s=n-(t*t-t)/2;
		printf("%d\n",(s+8)%9+1);
    }
   return 0;
}