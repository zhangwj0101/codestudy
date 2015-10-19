////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-04 21:21:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
/*
 * Dijkstra(M).cpp
 *
 *  Created on: 2010-9-4
 *      Author: Ambition
 */

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=105;	//µã¸öÊý

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
int Map[MAXN][MAXN];
int Path[MAXN];
int n;

int Dijkstra(int START,int END)
{
	priority_queue<City,vector<City>,CMP> QUE;
	Path[START]=0;
	City temp;
	temp.set(START,0);
	QUE.push(temp);
	while(!QUE.empty())
	{
		int Ups=QUE.top().LCity;
		if(Ups==END) return QUE.top().Cost;
		QUE.pop();
		for(int i=1;i<=n;i++){
			if(Map[Ups][i]==-1) continue;
			int tCost=Map[Ups][i];
			if(tCost+Path[Ups]<Path[i]||Path[i]==-1){
				Path[i]=tCost+Path[Ups];
				temp.set(i,Path[i]);
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
		memset(Map,-1,sizeof(Map));
		memset(Path,-1,sizeof(Path));
		for(int i=0;i<m;i++){
			int c1,c2,cost;
			scanf("%d%d%d",&c1,&c2,&cost);
			Map[c1][c2]=Map[c2][c1]=cost;
		}
		printf("%d\n",Dijkstra(1,n));
	}
}
