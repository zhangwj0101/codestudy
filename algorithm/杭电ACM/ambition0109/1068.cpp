////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-27 16:21:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1068
////Problem Title: 
////Run result: Accept
////Run time:718MS
////Run memory:552KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

bool markA[500],markB[500];
int n,list[500];
bool Graph[500][500];

bool dfs(int t)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		if(!Graph[t][i]) continue;
		temp=i;
		if(!markB[temp]) continue;
		markB[temp]=false;
		if(list[temp]==-1||dfs(list[temp]))
		{
			list[temp]=t;
			return true;
		}
	}
	return false;
} 

void main()
{
	int m,t,i,j,temp,num;
	while(cin>>n)
	{
		memset(Graph,false,sizeof(Graph));
		for(i=0;i<n;i++)
		{
			scanf("%d: (%d)",&t,&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&temp);
				Graph[t][temp]=true;
			}
		}
		memset(markA,true,sizeof(markA));
		memset(list,-1,sizeof(list));
		num=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(Graph[i][j])
				if(list[j]==-1)
				{
					markA[i]=false;
					list[j]=i;
					num++;
					break;
				}
		}
		for(i=0;i<n;i++)
		{
			if(markA[i])
			{
				memset(markB,true,sizeof(markB));
				for(j=0;j<n;j++)
				{
					if(!Graph[i][j]) continue;
					temp=j;
					if(!markB[temp]) continue;
					markB[temp] = false;
					if(list[temp]==-1||dfs(list[temp]))
					{
						list[temp]=i;
						num++;
						break;
					}
				}
				markA[i]=false;
			}
		}
		cout<<n-num/2<<endl;
	} 
} 
