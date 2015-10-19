////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-03-28 17:54:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2674
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:176KB
//////////////////System Comment End//////////////////
#include <stdio.h>
void main()
{
    long n,s[41];
    int i;
    s[0]=1;
    for(i=1;i<=40;i++)
      s[i]=s[i-1]*i%2009;
    while(scanf("%d",&n)==1)
      {
         if(n>=41)
			 puts("0");
         else
			 printf("%d\n",s[n]);
      }
}