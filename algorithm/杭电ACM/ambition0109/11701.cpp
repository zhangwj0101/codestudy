////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-11 17:41:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
int n,a,b;
char oper;
scanf("%d",&n);
{
getchar();
while(n--)
{
scanf("%c%d%d",&oper,&a,&b);
getchar();
switch(oper)
{
case'+':printf("%d\n",a+b);break;
case'-':printf("%d\n",a-b);break;
case'*':printf("%d\n",a*b);break;
case'/':if(a%b==0)printf("%d\n",a/b);
else printf("%.2lf\n",(double)a/(double)b);
}
}
}
return 0;
}