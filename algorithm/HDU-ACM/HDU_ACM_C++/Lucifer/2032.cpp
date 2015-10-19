////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-08 21:35:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
void print(int n)
{
    int a[100]={1};
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j>=1;j--)
            a[j]=a[j]+a[j-1];
        j=0;
        while(a[j++]!=0)
        {
            cout<<a[j-1];
            if(j<i+1)
                cout<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
   while(cin>>n)
   {
       print(n);
       cout<<endl;
   }
   return 0;
}