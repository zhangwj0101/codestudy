////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-19 11:23:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cmath>
int main(){long a,b;while(scanf("%ld%ld",&a,&b)==2)printf("%d\n",(int)pow(a%10,b%4+4)%10);return 0;}