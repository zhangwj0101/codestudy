////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-31 01:28:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
int main()
{long m1,m2,r1,r2,r3,l,i;char c[200];while(std::cin>>m1>>m2>>c){l=strlen(c);r1=r2=r3=0;for(i=0;i<l;i++)switch(c[i]){case 'A':r1=m1;break;case 'B':r2=m2;break;case 'C':m1=r3;break;case 'D':m2=r3;break;case 'E':r3=r1+r2;break;case 'F':r3=r1-r2;break;}std::cout<<m1<<","<<m2<<"\n";}return 0;}