////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-14 14:13:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3605
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:6160KB
//////////////////System Comment End//////////////////
#define N 100005
#include<iostream>
using namespace std;
int n,m,t;
bool map[N][12],used[12];
int cap[12],vlink[12],link[12][N];
bool dfs(int u)
{
    int i,j;
    for(i=1;i<=m;i++)
        if(!used[i]&&map[u][i])
        {
            used[i]=1;
            if(vlink[i]<cap[i])
            {
                link[i][vlink[i]++]=u;
                return true;
            }
            for(j=0;j<vlink[i];j++)    
                if(dfs(link[i][j]))
                {
                    link[i][j]=u;
                    return true;
                }
        }
    return false;
}
bool max_flow()
{
    int i;
    memset(link,0,sizeof(link));
    memset(vlink,0,sizeof(vlink));
    for(i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        if(!dfs(i))
            return false;
    }
    return true;
}
int main()
{
    while(cin>>n>>m)
    {
        int i,j,a;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {    
                scanf("%d",&a);
                if(a)
                    map[i][j]=1;
                else
                    map[i][j]=0;
            }    
        for(i=1;i<=m;i++)
            scanf("%d",&cap[i]);
        bool ans=max_flow();
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}