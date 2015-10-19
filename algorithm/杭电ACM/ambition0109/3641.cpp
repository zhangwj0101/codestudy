////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-19 18:29:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3641
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<string>
int prim[50],pn=0;
bool pp[101];
void pre()
{
int i,j;
for(i=2;i<=100;i++)
{
if(!pp[i]) prim[pn++]=i;
for(j=0;j<pn&&i*prim[j]<=100;j++)
{
pp[prim[j]*i]=1;
if(i%prim[j]==0) break;
}
}
}
__int64 fen(__int64 a,__int64 b)
{
__int64 ans=a*b,l=0,r=ans*3+1,mid,q;
while(l<=r)
{
mid=(l+r)>>1;
__int64 tt=mid/a;
q=0;
while(tt)
{
q+=tt;
tt/=a;
}
if(q<b) l=mid+1;
else if(q==b)break;
else r=mid-1;
}
mid/=a;
return mid*a;
}
int main()
{
__int64 t,n,a[101],b[101],q[50],max,i,j;
scanf("%I64d",&t);
pre();
while(t--)
{
memset(q,0,sizeof(q));
scanf("%I64d",&n);
for(i=0;i<n;i++)
{
scanf("%I64d%I64d",a+i,b+i);
for(j=0;j<pn&&prim[j]<=a[i];j++)
{
if(a[i]%prim[j]==0)
{
__int64 temp=0;
while(a[i]%prim[j]==0)
{
temp++;
a[i]/=prim[j];
}
q[j]+=temp*b[i];
}
}
}
max=0;
for(i=0;i<pn;i++)
{
__int64 tt=fen(prim[i],q[i]);
if(tt>max) max=tt;
}
printf("%I64d\n",max);
}
return 0;
}