////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-16 21:44:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1013
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include"stdio.h"
char *ch=new char[30];
long int input()
{
long int i,sum=0;
scanf("%s",ch);
 if(ch[0]=='0') return 0;
for(i=0;ch[i]!=0;i++)
 sum+=ch[i]-'0';
 return sum;
}
 void main()
{
long n;
 long root;
 n=input();
  while(n!=0)
{
root=32767;
while(root>=10)
{ root=0;
while(n!=0)
 {
root+=n%10;
 n=n/10;
  }
 n=root;
 }
 printf("%ld\n",root);
n=input();
 }
}
