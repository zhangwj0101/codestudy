////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-08 21:06:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1259
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
int n,m;
int x,y;
cin>>n;
while(n)
{
  cin>>m;
  int result=2;
  while(m)
  {
   cin>>x>>y;
   if(x==result)result=y;
   else
   if(y==result)result=x;
   m--;
  }
  cout<<result<<endl;
  n--;}
return 0;
}