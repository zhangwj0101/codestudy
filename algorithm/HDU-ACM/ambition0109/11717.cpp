////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-26 16:11:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:734MS
////Run memory:1352KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int c1[250000],c2[250000],v[51],m[51];
int main()
{
    int n,i,j,k,u,e;
    while (cin>>n && n>0)
    {
          int sum=0;
          for (int p=0;p<n;p++)
          {cin>>v[p]>>m[p];sum+=v[p]*m[p];}
          for (i=0;i<=sum;i++)
          {c1[i]=0;c2[i]=0;}
          for(k=0;k<=v[0]*m[0]&&(k<=sum/2);k=k+v[0])
          {c1[k]=1;}
          int t=m[0];
          for (i=1;i<n;i++)
          {
              for (j=0,e=0;e<=t;j+=v[0],e++)
              {
                  for (k=0,u=0;u<=m[i];k+=v[i],u++)
                  {c2[k+j]+=c1[j];}
              }
              t=j+k-v[0]-v[i];
              for (j=0;j<=sum;j++)
              {c1[j]=c2[j];c2[j]=0;}
          }
          int p;
          for (p=sum/2;p>=0;p--)
          {
              if (c1[p]!=0)            //不同的地方在这里!!!
                  {break;}
          }
          cout<<sum-p<<" "<<p<<endl;
    }
    return 0;
}