////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-19 20:09:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1085
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
/*
1085 Holding Bin-Laden Captive!
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
//母函数应用
//wa
#include <iostream>
#include <string>
using namespace std;

const int numMax=1000;
const int lmax=10000;

int main()
{
    int num[3],kinds[3]={1,2,5};
    int ca,cb,cc,total,temp,max;
    unsigned short c1[lmax+1]={0},c2[lmax+1]={0};
    bool out;
    while(cin>>num[0]>>num[1]>>num[2] && (num[0]+num[1]+num[2])) //注意结束时的逻辑
    {
        total=num[0]+num[1]*2+num[2]*5;
        for(ca=0;ca<=num[0];ca++)
            c1[ca]=1;
        max=num[0];
        for(ca=1;ca<3;ca++)
        {
            for(cb=0;cb<=max;cb++)
            {
                for(cc=0,temp=0;cc<=num[ca];cc++,temp+=kinds[ca])// ca*ca+1 = 1,2,5
                {   c2[temp+cb]+=c1[cb];}
            }
            if(temp+cb>max)
                max=temp+cb;
            for(cb=0;cb<=max;cb++)
            {   c1[cb]=c2[cb];c2[cb]=0;}  //注意c2清零
        }
        
        for(ca=0,out=false;ca<=total;ca++)
            if(!c1[ca])
            {   cout<<ca<<endl;out=true;break;}
        if(!out)
            cout<<ca<<endl;

        for(ca=0;ca<=total;ca++)
            c1[ca]=c2[ca]=0;
        //memset(c1,0,sizeof(c1));
        //memset(c2,0,sizeof(c2));
    }
    return 0;
}

