////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-01 16:37:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2040
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
int f(int n)
{
int s,i;
for(s=0,i=2;i<sqrt(1.0*n);i++)
if(n%i==0)
s+=i+n/i;
return s+1;
}
int main()
{
int i,m,a,b;
std::cin>>m;
for(i=0;i<m;i++)
{
std::cin>>a>>b;
if((a==f(b)))
{
if(b==f(a))
std::cout<<"YES\n";
}
else
std::cout<<"NO\n";
}
return 0;
}