////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-19 11:46:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2123
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
int main(){int c,i,j,k,n;std::cin>>c;for(k=0;k<c;k++){std::cin>>n;for(i=1;i<=n;i++){for(j=1;j<=n;j++){std::cout<<i*j;if(j<n)std::cout<<" ";}std::cout<<"\n";}}return 0;}