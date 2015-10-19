////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-20 18:59:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2464
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:156KB
//////////////////System Comment End//////////////////
/*
 * 2464.cpp
 *
 *  Created on: 2010-9-20
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;

int n,a,b,max;
int mina,minb;
int Link[30][2];
bool Mapa[10][10],Mapb[10][10];
bool Hash[10];
int take[10];

void Check()
{
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(Mapa[i][j]&&!Mapb[take[i]][take[j]]){
				cnt+=minb;
			}
			if(Mapb[take[i]][take[j]]&&!Mapa[i][j]){
				cnt+=mina;
			}
		}
	}
	if(cnt<max) max=cnt;
}

void Dfs(int t){
	if(t==n){
		Check();
		return;
	}
	for(int i=0;i<n;i++){
		if(Hash[i]) continue;
		take[t]=i;
		Hash[i]=true;
		Dfs(t+1);
		Hash[i]=false;
	}
}
int main()
{
	int cas=0;
	while(scanf("%d%d%d",&n,&a,&b),n||a||b){
		memset(Mapa,false,sizeof(Mapa));
		memset(Mapb,false,sizeof(Mapb));
		int ia,ib,da,db;
		scanf("%d%d%d%d",&ia,&ib,&da,&db);
		mina=ia<db?ia:db;
		minb=ib<da?ib:da;
		max=1000000;
		for(int i=0;i<a;i++){
			int p1,p2;
			scanf("%d%d",&p1,&p2);
			Mapa[p1][p2]=Mapa[p2][p1]=true;
		}
		for(int j=0;j<b;j++){
			int p1,p2;
			scanf("%d%d",&p1,&p2);
			Mapb[p1][p2]=Mapb[p2][p1]=true;
		}
		Dfs(0);
		printf("Case #%d: %d\n",++cas,max);
	}
}
