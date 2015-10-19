////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-04 20:19:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
/*
 * SPFA(G).cpp
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
const int MAX_SIZE=100;

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
	memset(Path,-1,sizeof(Path));
	memset(Hash,false,sizeof(Hash));
	Path[START]=0;
	queue<int> QUE;
	QUE.push(START);
	while(!QUE.empty())		//SPFA
	{
		int Ups=QUE.front(); QUE.pop();
		Hash[Ups]=false;
		for(unsigned i=0;i<Graph[Ups].size();i++){
			int tLC=Graph[Ups][i].LCity;
			if(Graph[Ups][i].Cost+Path[Ups]<Path[tLC]||Path[tLC]==-1){
				Path[tLC]=Graph[Ups][i].Cost+Path[Ups];
				if(!Hash[tLC]){
					QUE.push(tLC);
					Hash[tLC]=true;
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
