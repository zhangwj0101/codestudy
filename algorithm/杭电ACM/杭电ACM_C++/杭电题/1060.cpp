////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-19 20:16:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
/*
1060 Leftmost Digit
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream>
#include <cmath>
using namespace std;

const int NMAX=1000000000;

double Normal(double num,int & n10)
{
    n10=(int)log10(num);
    return num/pow(10.0,n10);
}

int main()
{
    int t,n,digit,n10,temp;
    double fn;
    while(cin>>t)
    {
        for(int ca=0;ca<t;ca++)
        {
            cin>>n;
            fn=Normal((double)n,n10);
            fn=pow((double)n,fn);
            fn=Normal(fn,temp);
            for(int cb=0;cb<n10;cb++)
            {
                fn=pow(fn,10);
                fn=Normal(fn,temp);
            }

            digit=(int)Normal(fn,n10);
            cout<<digit<<endl;
        }
    }
    return 0;
}

