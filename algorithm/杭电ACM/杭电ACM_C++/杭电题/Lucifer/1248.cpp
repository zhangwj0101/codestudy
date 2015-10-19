////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-31 00:36:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
int main(){int i,n,k,t;std::cin>>n;for(i=0;i<n;i++){std::cin>>t;k=t/150;t=t-150*k;if(t/50<k)k=t/50;t-=k*50;std::cout<<t<<"\n";}return 0;}