////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-10 20:27:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1396
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int tr[501] = {0};
int main()
{
  int n,i,j,r;
  tr[1] = 1;
  for(i = 2; i < 501; i ++)
  {
    tr[i] = tr[i-1] +(i*i+3*i-2)/2;
    for(j = 2; j < i; j ++)
    {
        for(r = 2; r <= j; r++)
        {
          if(i - j == r)tr[i] += j-r+1;//////新加的大的倒三角
        }
    }
  }
  while(scanf("%d",&n) != EOF)
  {
    printf("%d\n",tr[n]);
  }
  return 0;
}