////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 17:54:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
    int n,i,a,b;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
		a=a%100;
		b=b%100;
        cout<<(a+b)%100<<endl;
    }
   return 0;
}