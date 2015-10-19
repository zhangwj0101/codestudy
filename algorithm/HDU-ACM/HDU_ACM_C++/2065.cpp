////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-01 13:52:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2065
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<stdio.h>
__int64 a[23]; 
int main() 
{ 
__int64 n,sum,i,t,key; 
for(n=1;n<23;n++)
{ 
	sum=1;
	sum=((sum<<2*n)+(sum<<n+1))/4;
	sum%=100; 
	a[n]=sum; 
}
while(scanf("%I64d",&t) && t!=0) 
{
for(i=1;i<=t;i++) 
{
scanf("%I64d",&key);
if(key>2)
{
	key=(key-2)%20;
	key=key?(key+2):22;
}
printf("Case %I64d: %I64d\n",i,a[key]);
}
printf("\n"); 
}
return 0; 
}