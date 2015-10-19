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
//a[i]: ��¼���ϵĸ���
//b[i]: ��¼����Ĳ��ɷָ��4*i�ĸ��� 
/* 
      -- �� ƽ��
      |
      |:  ���� 

����  
          ||  �ɷָ��  |  ��  | 
          ||            |      |
          ||            |      |
          ||            |      |
          
          --|  �ɷָ��  --  �� |                          
          --|            --      |                    
          --|            --      |                    
          --|            --      |                    
    
    
    ���ɷָ�������£� 
      |  ||      --    --    ||    |--    --|    |--|    ----  ----                          
      |  ||      --    ||    ||    |--    --|    |--|    |--|  ----                                        
      |  --      --    ||    --    --|    |--    ----    |--|  |--|          
      |  --      --    --    --    --|    |--    ----    ----  |--|      
      1  (        4          )    (    2  )    (      3          )
      �����4*i���ⲻ�ɷָ���Ա�2�����ĸ���Ϊ3 �����Ե�Ϊ2 
      
  ��      
*/ 
int main()
{
    __int64 n,w,i,j;
    a[0]=a[1]=1;
    b[1] = 1;
    b[2] = 4;
    for(i = 3; i <= 30; i++)      //�����4*i���ⲻ�ɷָ���Ա�2�����ĸ���Ϊ3 �����Ե�Ϊ2  
          if(i % 2)b[i] = 2;    
          else b[i] = 3;
    for(i = 2; i < 30; i++){
        for(j = 1; j <= i; j++)
          a[i] += a[i-j] * b[j];    //a[i-j]�ĸ��� * ���ɷָ��b[j] 
    }
    
    
    scanf("%I64d", &n);
    for(i = 1; i <= n; i++){
        scanf("%I64d", &w);
        printf("%I64d %I64d\n", i, a[w]);
    }
    return 0;
}