////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 23:03:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1284
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
//³­µÄ
#include<stdio.h>
long a[32768];
int main()
{
  long n,i;
  a[0]=0;
  for( i = 1 ; i < 32768 ; i++ )
    {  if(i%6==1&&i!=1)
          a[i]=a[i-1]+(i/6);
      else a[i]=a[i-1]+(i/6+1);  }
      while(scanf("%d",&n)!=EOF&&n<32768)
      printf("%d\n",a[n]);
}