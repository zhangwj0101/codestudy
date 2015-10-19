////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-02 11:24:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2051
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
int main(){int i,t,b[20];while(std::cin>>t){for(i=0;t>0;i++,t>>=1)b[i]=t%2;while(--i>=0)std::cout<<b[i];std::cout<<"\n";}return 0;}