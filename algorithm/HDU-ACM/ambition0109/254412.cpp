////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-04 20:53:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:304KB
//////////////////System Comment End//////////////////
/*
 * Dijkstra(G).cpp
 *
 *  Created on: 2010-9-4
 *      Author: Ambition
 */

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=105;	//µã¸öÊý
const int INF=0x7fffffff;

struct City{
	unsigned LCity;
	int Cost;
	void set(int nCity,int nCost){
		LCity=nCity;Cost=nCost;
	}
};
struct CMP{
	bool operator() (const City& a,const City& b){
		return a.Cost>b.Cost;
	}
};
vector<vector<City> > Graph;
int n;

int Dijkstra(int START,int END)
{
	priority_queue<City,vector<City>,CMP> QUE;
	vector<int> Path(MAXN,INF);
	Path[START]=0;
	City temp;
	temp.set(START,0);
	QUE.push(temp);
	while(!QUE.empty())
	{
		int Ups=QUE.top().LCity;
		if(Ups==END) return QUE.top().Cost;
		QUE.pop();
		for(unsigned i=0;i<Graph[Ups].size();i++){
			int tCity=Graph[Ups][i].LCity;
			int tCost=Graph[Ups][i].Cost;
			if(tCost+Path[Ups]<Path[tCity]){
				Path[tCity]=tCost+Path[Ups];
				temp.set(tCity,Path[tCity]);
				QUE.push(temp);
			}
		}
	}
	return -1;
}

int main()
{
	int m;
	while(scanf("%d%d",&n,&m),n||m){
		Graph.clear();
		Graph.resize(n+1);
		for(int i=0;i<m;i++){
			int c1,c2,cost;
			scanf("%d%d%d",&c1,&c2,&cost);
			City temp;
			temp.set(c2,cost);
			Graph[c1].push_back(temp);
			temp.set(c1,cost);
			Graph[c2].push_back(temp);
		}
		printf("%d\n",Dijkstra(1,n));
	}
}
