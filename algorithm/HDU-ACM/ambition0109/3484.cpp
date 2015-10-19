////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-23 20:37:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3484
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
const int N=100;
int a[N],b[N],m,n;
while(scanf("%d %d",&m,&n) && (m!=-1 && n!=-1))
{
   int i,j,temp;
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   for(i=0; i<m; i++)
   {
    for(j=0; j<n; j++)
    {
     scanf("%d",&temp);
     if(temp)
      a[i]++;
    }
   }
   for(i=0; i<m; i++)
   {
    for(j=0; j<n; j++)
    {
     scanf("%d",&temp);
     if(temp)
      b[i]++;
    }
   }
   for(i=0; i<m; i++)
   {
    if(a[i]!=b[i] && a[i]!=(n-b[i]))
     break;
   }
   puts(i==m?"Yes":"No");
}
return 0;
}