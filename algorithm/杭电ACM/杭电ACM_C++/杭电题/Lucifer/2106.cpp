////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-24 18:04:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2106
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
char num[32];
int trans(int x,int y)
{
    int i,sl,s,yn;
    sprintf(num,"%d",x);
    sl=strlen(num);
    s=num[sl-1]-'0';
    for(yn=y,i=sl-2;i>=0;i--,yn*=y)
    {
     s+=(num[i]-'0')*yn;
    }
    return s;
}
int main()
{
    int n,s,x,y;
    while(cin>>n)
    {
     s=0;
     while(n--)
     {
      scanf("%d(%d)",&x,&y);
      s+=trans(x,y);
     }
     cout<<s<<endl;
    }
    return 0;
}