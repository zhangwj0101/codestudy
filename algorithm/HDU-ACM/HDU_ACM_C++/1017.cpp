////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-17 16:26:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1017
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int doProcess(int n,int m)
{
    int temp,count=0;
    for (int a=1;a<n-1;++a)
    {
        for (int b=a+1;b<n;++b)
        {
            temp = a*a+b*b+m;
            if (temp%(a*b)==0)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int caseNum,n,m,inerCase;
    while (cin>>caseNum)
    {
        for (int i=0;i<caseNum;++i)
        {
            inerCase = 1;
            while (cin>>n>>m&&!(n==0&&m==0))
            {
                cout<<"Case "<<inerCase<<": "<<doProcess(n,m)<<endl;
                inerCase++;
            }
            if (i!=caseNum-1)
            {
                cout<<endl;
            }
        }
    }
    return 0;
}