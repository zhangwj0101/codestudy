////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-16 19:26:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1141
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int FB[25]={3,5,8,12,20,34,57,98,170,300,536,966,1754,3210,5910,10944,20366,38064,71421,134480,254016};
int main()
{
    int y;
    while(cin>>y&&y)
    {
     y=(y-1960)/10;
     cout<<FB[y]<<endl;
    }
    return 0;
}