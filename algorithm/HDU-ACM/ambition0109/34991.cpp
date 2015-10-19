////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-04 13:41:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3499
////Problem Title: 
////Run result: Accept
////Run time:3375MS
////Run memory:13012KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;
const int MAX_SIZE=100000;	//µã¸öÊý
const __int64 INF=0x7fffffffffffLL;

struct City{
	int LCity;
	int Cost;
};
struct Q{
	int city;
	__int64 cost;
	void set(int nc,__int64 ncc){
		city=nc;cost=ncc;
	}
};
struct compare{
	bool operator() (const Q& a,const Q& b){
		return a.cost>b.cost;
	}
};
vector<vector<City> > Graph;
__int64 Path[MAX_SIZE+1];
int Pre[MAX_SIZE+1];
map<string,int> citys;
int n;

__int64 Dijkstra(int START,int END)
{
	priority_queue<Q,vector<Q>,compare> QUE;
	for(int i=1;i<=n;i++){
		Path[i]=INF;
	}
	Pre[START]=0;
	Path[START]=0;
	Q temp;
	temp.set(START,0);
	QUE.push(temp);
	while(QUE.top().city!=END)
	{
		int Ups=QUE.top().city;
		QUE.pop();
		for(unsigned i=0;i<Graph[Ups].size();i++){
			__int64 tcost;
			if(Graph[Ups][i].Cost>Pre[Ups]){
				tcost=Graph[Ups][i].Cost/2+Path[Ups]+(Pre[Ups]+1)/2;
				Pre[Graph[Ups][i].LCity]=Graph[Ups][i].Cost;
			}else{
				tcost=Graph[Ups][i].Cost+Path[Ups];
				Pre[Graph[Ups][i].LCity]=Pre[Ups];
			}
			if(tcost<Path[Graph[Ups][i].LCity]){
				Path[Graph[Ups][i].LCity]=tcost;
				temp.set(Graph[Ups][i].LCity,tcost);
				QUE.push(temp);
			}
		}
		if(QUE.empty()) return -1;
	}
	return Path[END];
}

void main()
{
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
		citys.clear();
		Graph.clear();
		Graph.resize(n+1);
		int t=1;
		for(int i=0;i<m;i++){
			char c1[50],c2[50];
			int cost;
			scanf("%s %s %d",c1,c2,&cost);
			if(!citys[c1]) citys[c1]=t++;
			if(!citys[c2]) citys[c2]=t++;
			City temp;
			temp.LCity=citys[c2];temp.Cost=cost;
			Graph[citys[c1]].push_back(temp);
		}
		char c1[50],c2[50];
		scanf("%s %s",c1,c2);
		if(!(citys[c1]&&citys[c2])){
			puts("-1");
			continue;
		}
		__int64 cost;
		cost=Dijkstra(citys[c1],citys[c2]);
		printf("%I64d\n",cost);
	}
}