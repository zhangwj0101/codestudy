////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-25 21:00:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1242
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
/*
 * 1242.cpp
 *
 *  Created on: 2010-11-25
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define M 205

struct Node{
	int x,y,s;
	Node(int _x=0,int _y=0,int _s=0):
		x(_x),y(_y),s(_s){}
	friend bool operator <(const Node& a,const Node& b){
		return a.s>b.s;
	}
};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char Map[M][M];
int sx,sy,ex,ey,n,m;

int BFS(int sx,int sy){
	priority_queue<Node,vector<Node> > Que;
	Que.push(Node(sx,sy,0));
	while(!Que.empty()){
		Node tmp=Que.top();
		Que.pop();
		int ts=tmp.s+1;
		for(int i=0;i<4;i++){
			int tx=tmp.x+dir[i][0];
			int ty=tmp.y+dir[i][1];
			if(tx==ex&&ty==ey) return ts;
			int tts=ts;
			if(tx<0||ty<0||tx>=n||ty>=m) continue;
			if(Map[tx][ty]=='#') continue;
			if(Map[tx][ty]=='x') tts+=1;
			Que.push(Node(tx,ty,tts));
			Map[tx][ty]='#';
		}
	}
	return -1;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%s",Map[i]);
			for(int j=0;j<m;j++){
				if(Map[i][j]=='a'){
					sx=i,sy=j;
					Map[i][j]='#';
				}
				if(Map[i][j]=='r'){
					ex=i,ey=j;
				}
			}
		}
		int Ans=BFS(sx,sy);
		if(Ans==-1) puts("Poor ANGEL has to stay in the prison all his life.");
		else printf("%d\n",Ans);
	}
}
