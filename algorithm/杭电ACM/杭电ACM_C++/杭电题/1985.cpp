////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-12 09:49:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1985
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
const double k2p=2.2046;
const double p2k=0.4536;
const double l2g=0.2642;
const double g2l=3.7854;
int main()
{
    int n,i;
    double m;
    char  s[3];
    cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>m>>s;
            if(!strcmp(s,"lb"))
            {
                m*=p2k;
                strcpy(s,"kg");
            }
            else if(!strcmp(s,"kg"))
            {
                m*=k2p;
                strcpy(s,"lb");
            }
            else if(!strcmp(s,"l"))
            {
                m*=l2g;
                strcpy(s,"g");
            }
            else if(!strcmp(s,"g"))
            {
                m*=g2l;
                strcpy(s,"l");
            }
            printf("%d %.4lf %s\n",i,m,s);
        }
  return 0;
}