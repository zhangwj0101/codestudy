////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-08 21:44:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2039
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
    int n,i;
	double a,b,c;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        if((a+b>c)&&(b+c>a)&&(c+a>b))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
   }
   return 0;
}