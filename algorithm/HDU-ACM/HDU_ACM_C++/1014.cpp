////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-17 15:46:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<cstdio>
int main(){long s,m,i,k;for(;scanf("%ld%ld",&s,&m)+1;printf("%10d%10d    %s Choice\n\n",s,m,(k-1)?"Bad":"Good"))for(i=1;i<=(s>m?m:s);i++)if(!(s%i||m%i))k=i;return 0;}