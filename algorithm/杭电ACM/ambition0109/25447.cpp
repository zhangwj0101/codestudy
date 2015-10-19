////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-04 19:55:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:324KB
//////////////////System Comment End//////////////////
/*
 * SPFA.cpp
 *
 *  Created on: 2010-9-4
 *      Author: Ambition
 */
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX_SIZE=150;
const int INF=0x7fffffff;

struct City
{
	int LCity,Cost;
	void set(int nCity,int nCost){
		LCity=nCity;Cost=nCost;
	}
};
vector<vector<City> > Graph;
int Path[MAX_SIZE+1];
bool Hash[MAX_SIZE+1];
int n;

void SPFA(int START)
{
	fill(Path,Path+n+1,INF);
	Path[START]=0;
	memset(Hash,false,sizeof(Hash));
	queue<int> QUE;
	QUE.push(START);
	while(!QUE.empty())		//SPFA
	{
		int Ups=QUE.front(); QUE.pop();
		Hash[Ups]=false;
		for(unsigned i=0;i<Graph[Ups].size();i++){
			if(Graph[Ups][i].Cost+Path[Ups]<Path[Graph[Ups][i].LCity]){
				Path[Graph[Ups][i].LCity]=Graph[Ups][i].Cost+Path[Ups];
				if(!Hash[Graph[Ups][i].LCity]){
					QUE.push(Graph[Ups][i].LCity);
					Hash[Graph[Ups][i].LCity]=true;
				}
			}
		}
	}
}
int main(){
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
        SPFA(1);
        printf("%d\n",Path[n]);
    }
}
