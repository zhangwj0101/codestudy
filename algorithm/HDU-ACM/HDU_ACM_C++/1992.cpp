////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-01 15:47:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1992
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#define MAXN 50

__int64 a[MAXN],b[MAXN];
//a[i]: 记录符合的个数
//b[i]: 记录特殊的不可分割的4*i的个数 
/* 
      -- ： 平放
      |
      |:  竖放 

例如  
          ||  可分割成  |  和  | 
          ||            |      |
          ||            |      |
          ||            |      |
          
          --|  可分割成  --  和 |                          
          --|            --      |                    
          --|            --      |                    
          --|            --      |                    
    
    
    不可分割的有如下： 
      |  ||      --    --    ||    |--    --|    |--|    ----  ----                          
      |  ||      --    ||    ||    |--    --|    |--|    |--|  ----                                        
      |  --      --    ||    --    --|    |--    ----    |--|  |--|          
      |  --      --    --    --    --|    |--    ----    ----  |--|      
      1  (        4          )    (    2  )    (      3          )
      后面的4*i特殊不可分割可以被2整除的个数为3 不可以的为2 
      
  等      
*/ 
int main()
{
    __int64 n,w,i,j;
    a[0]=a[1]=1;
    b[1] = 1;
    b[2] = 4;
    for(i = 3; i <= 30; i++)      //后面的4*i特殊不可分割可以被2整除的个数为3 不可以的为2  
          if(i % 2)b[i] = 2;    
          else b[i] = 3;
    for(i = 2; i < 30; i++){
        for(j = 1; j <= i; j++)
          a[i] += a[i-j] * b[j];    //a[i-j]的个数 * 不可分割的b[j] 
    }
    
    
    scanf("%I64d", &n);
    for(i = 1; i <= n; i++){
        scanf("%I64d", &w);
        printf("%I64d %I64d\n", i, a[w]);
    }
    return 0;
}