////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-04 20:43:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*
 * SPFA(M).cpp
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
const int INF=0x7fffffff;

int Map[MAX_SIZE+1][MAX_SIZE+1];
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
		for(unsigned i=1;i<=n;i++){
			if(Map[Ups][i]==-1) continue;
			if(Map[Ups][i]+Path[Ups]<Path[i]){
				Path[i]=Map[Ups][i]+Path[Ups];
				if(!Hash[i]){
					QUE.push(i);
					Hash[i]=true;
				}
			}
		}
	}
}
int main(){
    int m;
    while(scanf("%d%d",&n,&m),n||m){
    	memset(Map,-1,sizeof(Map));
        for(int i=0;i<m;i++){
            int c1,c2,cost;
            scanf("%d%d%d",&c1,&c2,&cost);
            Map[c1][c2]=Map[c2][c1]=cost;
        }
        SPFA(1);
        printf("%d\n",Path[n]);
    }
}
