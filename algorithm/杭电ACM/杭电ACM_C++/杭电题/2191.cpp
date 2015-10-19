////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-01 12:19:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2191
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

class Dp
{
    public:
        Dp(){memset(dp,0,sizeof(dp));}
        int* operator[](int i)
        {
            return dp[i&1];
        }
    private:
        int dp[2][2001];
};
int p[2001],h[2001];

int main()
{
    int C,n,m;
    cin>>C;
    while(C--)
    {
        cin>>n>>m;
        Dp dp;
        int i,j,k=1;
        int a,b,c;
        for(i=1;i<=m;++i)
        {
              scanf("%d %d %d",&a,&b,&c);
              if(c==1)
                  p[k]=a,h[k++]=b;
              else
              {
                  while(c--)
                      p[k]=a,h[k++]=b;
              }
        }
        m=k-1;
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(p[i]>j) dp[i][j]=dp[i-1][j];
                else
                {
                    dp[i][j]=max(dp[i-1][j],h[i]+dp[i-1][j-p[i]]);
                }
            }
        }
        cout<<dp[m][n]<<endl;
    }  
}