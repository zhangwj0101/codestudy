////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-27 16:39:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1068
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;

bool markA[500],markB[500];
int list[500];
int edge,num;
vector<vector<int> > Graph;

bool dfs(int n)
{
    int temp;
    for(int i=0;i<Graph[n].size();i++)
    {
        temp=Graph[n][i];
        if(!markB[temp]) continue;
        markB[temp]=false;
        if(list[temp]==-1||dfs(list[temp]))
        {
            list[temp]=n;
            return true;
        }
    }
    return false;
} 

void main()
{
    int t,n,m,i,j,temp;
    while(cin>>n)
    {
        Graph.clear();
        Graph.resize(n);
        for(i=0;i<n;i++)
        {
            scanf("%d: (%d)",&t,&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&temp);
				Graph[t].push_back(temp);
			}
        } 
        memset(markA,true,sizeof(markA));
        memset(list,-1,sizeof(list));
        num=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<Graph[i].size();j++)
                if(list[Graph[i][j]]==-1)
                {
                    markA[i]=false;
                    list[Graph[i][j]]=i;
                    num++;
                    break;
                }
        }
        for(i=0;i<n;i++)
        {
            if(markA[i])
            {
                if(!Graph[i].empty())
                {
                    memset(markB,true,sizeof(markB));
                    for(j=0;j<Graph[i].size();j++)
                    {
                        temp=Graph[i][j];
                        if(!markB[temp]) continue;
                        markB[temp] = false;
                        if(list[temp]==-1||dfs(list[temp]))
                        {
                            list[temp]=i;
                            num++;
                            break;
                        }
                    }
                }
                markA[i]=false;
            }
        }
        cout<<n-num/2<<endl;
    } 
} 