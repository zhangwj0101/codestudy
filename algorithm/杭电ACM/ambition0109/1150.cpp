////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-27 14:08:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1150
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool mark1[100],mark2[100];
int list[100];
int mA,mB,edge,num;
vector<vector<int> > Graph;

bool dfs(int to)
{
	register int i,point,s = list[to];
	for(i=0;i<Graph[s].size();i++)
	{
		point = Graph[s][i];
		if(!mark2[point])
			continue;
		mark2[point] = false;
		if(list[point]==-1 || dfs(point))
		{
			list[point] = s;
			return true;
		}
	}
	return false;
} 
void Solve()
{
	int i,j,point;
	memset(mark1,true,sizeof(mark1));
	memset(list,-1,sizeof(list));
	num=0;
	for(i=0;i<mA;i++)
	{
		for(j=0;j<Graph[i].size();j++)
			if(list[Graph[i][j]]==-1)
			{
				mark1[i]=false;
				list[Graph[i][j]]=i;
				num++;
				break;
			} 
	}
	for(i=0;i<mA;i++)
	{
		if(mark1[i])
		{
			if(!Graph[i].empty())
			{
				memset(mark2,true,sizeof(mark2));
				for(j=0;j<Graph[i].size();j++)
				{
					point=Graph[i][j];
					if(!mark2[point]) continue;
					mark2[point] = false;
					if(list[point] == -1||dfs(point))
					{
						list[point] = i;
						num++;
						break;
					}
				}
			}
			mark1[i] = false; 
		} 
	} 
	if(list[0] != -1) cout<<num-1<<endl;
	else cout<<num<<endl;
} 
int main()
{
	int t,A,B;
	while(cin>>mA)
	{
		if(mA == 0)break;
		Graph.clear();
		Graph.resize(mA);
		cin >> mB >> edge;
		for(int i=0;i<edge;i++)
		{
			cin >> t >> A >> B;
			if(A==0||B==0) continue;
			Graph[A].push_back(B);
		} 
		Solve();
	} 
	return 0;
} 
