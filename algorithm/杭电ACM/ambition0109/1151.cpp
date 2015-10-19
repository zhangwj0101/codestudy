////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-27 14:33:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1151
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;

bool markA[150],markB[150];
int list[150];
int mA,mB,edge,num;
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
	int n,A,B,i,j,temp;
	for(cin>>n;n>0;n--)
	{
		cin>>mA;
		Graph.clear();
		Graph.resize(mA+1);
		cin>>edge;
		for(i=0;i<edge;i++)
		{
			cin>>A>>B;
			Graph[A].push_back(B);
		} 
		memset(markA,true,sizeof(markA));
		memset(list,-1,sizeof(list));
		num=0;
		for(i=1;i<=mA;i++)
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
		for(i=1;i<=mA;i++)
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
		cout<<mA-num<<endl;
	} 
} 
