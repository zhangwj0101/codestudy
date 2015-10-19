////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-18 17:27:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1065
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
const float Pi=3.1415926;
int main()
{
    int n,ca,z,land;
    float x,y,r,len;
    cin>>n;
    for(ca=1;ca<=n;ca++)
    {
        cin>>x>>y;
        len=sqrt(x*x+y*y);
        r=0;z=0;land=0;
        while(len>r)
        {
            land+=50;
            r=sqrt(2*land/Pi);
            z++;
        }
        cout<<"Property "<<ca<<": This property will begin eroding in year "<<z<<".\n";
    }
    cout<<"END OF OUTPUT.\n";
    return 0;
}