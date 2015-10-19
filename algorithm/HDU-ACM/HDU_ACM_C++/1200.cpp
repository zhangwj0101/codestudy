////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 08:22:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
//³­µÄ
int main()
{
int columns;
char str[200];
char ch[100][20];
int i,j,k;
int len;
while(scanf("%d",&columns)!=EOF)
{
   if(columns ==0)
    break;
   scanf("%s",str);
   len =strlen(str);
   int len1=len/columns;
   i=0;
   k=0;
   while( k<len)
   {
     if( (k/columns )%2==0)
         for(j=0;j<columns;j++)
          ch[i][j]=str[k++];
        else
      for(j=columns-1;j>=0;j--)
       ch[i][j]=str[k++];
      i++;
   }
   k=0;
    for(j=0;j<columns;j++)
      for(i=0;i<len1;i++)
      {
       str[k++]=ch[i][j];
      }
     str[k]='\0';
    printf("%s\n",str);
}
return 0;
}
