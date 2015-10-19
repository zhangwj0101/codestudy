////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 21:23:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1420
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
/*
1420 Prepared for New Acmer
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 256 K

GUN C++
*/
//用到了指数式乘法
#include <iostream>
using namespace std;
int main()
{
    int t,a,b,c;
    __int64 temp,an;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        an=a%c;
        temp=1;
        while(b>1)
        {
            if(b%2==1)
            {   temp*=an;temp%=c;b--;}
            else
            {
                an*=an;
                an%=c;
                b/=2;
            }
        }
        cout<<(int)((an*temp)%c)<<endl;
    }
    return 0;
}