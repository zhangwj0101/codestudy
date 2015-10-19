////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-13 19:49:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1000
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:176KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

inline bool scan_d(int &num)
{
    char in;bool PN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ PN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
        num*=10,num+=in-'0';
    }
    if(PN) num=-num;
    return true;
}

void main()
{
int a,b;
while(scan_d(a)&&scan_d(b))
printf("%d\n",a+b);
}