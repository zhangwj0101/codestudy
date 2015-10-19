////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-01 13:27:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2153
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
int i,j,k,n,a[10][10];
while(cin>>n)
{
for(i=0;i<10;i++)
for(j=0;j<10;j++)
a[i][j]=0;
for(k=1,i=0;i<=n-1;i++,k++)
{
a[0][i]=k;
a[i][n-1]=k+n-1;
a[n-1][n-1-i]=k+2*n-2;
a[n-1-i][0]=k+3*n-3;
}
a[0][0]=1;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cout<<setw(3)<<setfill(' ');
if(a[i][j]==0)
cout<<' ';
else
cout<<a[i][j];
}
cout<<endl;
}
}
return 0;
}