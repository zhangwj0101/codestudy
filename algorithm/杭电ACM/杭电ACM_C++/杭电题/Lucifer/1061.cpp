////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-01 15:28:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1061
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
int main(){int i,t,n,a;std::cin>>t;for(i=0;i<t;i++){std::cin>>n;a=n%10;a=(int)pow(a,n%4+4)%10;std::cout<<a<<"\n";}return 0;}