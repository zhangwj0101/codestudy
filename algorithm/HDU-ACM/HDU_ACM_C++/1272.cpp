////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-12 11:06:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:628KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int pre[100010],pa,pb,adj,arc;
int find(int key)
{
    while(pre[key]>-1)
        key=pre[key];
    return key;
}
int join(int a,int b)
{
    pa=find(a);
    pb=find(b);
    if(pa==pb)
        return 1;
    arc++;
    if(pre[pa]==-1 && pre[pb]==-1)
    {
        adj+=2;
        pre[pa]=-2;
        pre[pb]=pa;
    }
    else if(pre[pa]==-1 && pre[pb]!=-1)
    {
        adj++;
        pre[pa]=pb;
        pre[pb]--;
    }
    else if(pre[pa]!=-1 && pre[pb]==-1)
    {
        adj++;
        pre[pb]=pa;
        pre[pa]--;
    }
    else
    {
        if(pre[pa]<pre[pb])
            pre[pa]+=pre[pb], pre[pb]=pa;
        else
            pre[pb]+=pre[pa], pre[pa]=pb;
    }
    return 0;
}
int main()
{
    int a,b,k=0,tem,flag;
    while(scanf("%d %d",&a,&b) !=EOF)
    {
        if(a==-1 && b==-1)
            break;
        if(a==0 && b==0)
        {
            printf("Yes\n");
            continue;
        }
        memset(pre,-1,sizeof(pre));
        adj=arc=0, flag=1;
        tem=join(a,b);
        scanf("%d %d",&a,&b);
        while(a!=0 || b!=0)
        {
            if(flag)
            {
                tem=join(a,b);
                if(tem)  flag=0;
            }
            scanf("%d %d",&a,&b);
        }
        if(flag && adj==arc+1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}