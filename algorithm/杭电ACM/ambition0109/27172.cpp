////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-24 18:37:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2717
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:472KB
//////////////////System Comment End//////////////////
/*
 * 2717.cpp
 *
 *  Created on: 2010-9-24
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Unit{
	int Pos,step;
	void set(int nP,int nS){
		Pos=nP;step=nS;
	}
};

int s,e;
bool Hash[100005];
int Bfs(){
	queue<Unit> Que;
	Unit tmp;
	tmp.set(s,0);
	Que.push(tmp);
	Hash[s]=true;
	while(true){
		int tP=Que.front().Pos;
		int tS=Que.front().step;
		Que.pop();
		if(tP+1==e) return tS+1;
		if(tP-1==e) return tS+1;
		if(tP*2==e) return tS+1;
		if(tP>0&&!Hash[tP-1]){
			tmp.Pos=tP-1;
			tmp.step=tS+1;
			Hash[tP-1]=true;
			Que.push(tmp);
		}
		if(tP<e&&!Hash[tP+1]){
			tmp.Pos=tP+1;
			tmp.step=tS+1;
			Hash[tP+1]=true;
			Que.push(tmp);
		}
		if(tP<e){
			if((tP<<1)>100000) continue;
			if(Hash[tP<<1]) continue;
			tmp.Pos=tP<<1;
			tmp.step=tS+1;
			Hash[tP<<1]=true;
			Que.push(tmp);
		}
	}
}

int main()
{
	while(scanf("%d%d",&s,&e)!=EOF){
		if(s==e){
			puts("0");
			continue;
		}
		memset(Hash,false,sizeof(Hash));
		printf("%d\n",Bfs());
	}
}
