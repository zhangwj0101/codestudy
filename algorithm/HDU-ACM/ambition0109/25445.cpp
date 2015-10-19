////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-06 15:34:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=105;	//µã¸öÊý
const int INF=0x7fffffff;

struct C{
	unsigned City;
	int Cost;
	void set(int nCity,int nCost){
		City=nCity;Cost=nCost;
	}
};
struct Q{
	unsigned City;
	int Cost;
	void set(int nCity,int nCost){
		City=nCity;Cost=nCost;
	}
};
struct CMP{
	bool operator() (const Q& a,const Q& b){
		return a.Cost>b.Cost;
	}
};
vector<vector<C> > Graph;
int n;

int Dijkstra(int START,int END)
{
	priority_queue<Q,vector<Q>,CMP> QUE;
	vector<int> Path(MAXN,INF);
	Path[START]=0;
	Q temp;
	temp.set(START,0);
	QUE.push(temp);
	while(!QUE.empty())
	{
		int Ups=QUE.top().City;
		if(Ups==END) return QUE.top().Cost;
		QUE.pop();
		for(unsigned i=0;i<Graph[Ups].size();i++){
			int tCity=Graph[Ups][i].City;
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
			C temp;
			temp.set(c2,cost);
			Graph[c1].push_back(temp);
			temp.set(c1,cost);
			Graph[c2].push_back(temp);
		}
		printf("%d\n",Dijkstra(1,n));
	}
}