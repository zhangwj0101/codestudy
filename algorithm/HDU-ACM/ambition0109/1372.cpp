////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-02 11:09:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1372
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*
 * 1372.cpp
 *
 *  Created on: 2010-12-2
 *      Author: hduacm
 */

#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct Node{
	int x, y, step;
	Node(int _x,int _y,int _s):
		x(_x),y(_y),step(_s){}
};

int ex,ey;
int dir[8][2]={{1,2},{2,1},{-1,-2},{-2,-1},{2,-1},{-1,2},{-2,1},{1,-2}};
bool Map[9][9];
int bfs(int sx,int sy){
	queue<Node> que;
	que.push(Node(sx,sy,0));
	Map[sx][sy]=true;
	while(!que.empty()){
		int tx=que.front().x;
		int ty=que.front().y;
		int ts=que.front().step;
		que.pop();
		for(int i=0;i<8;i++){
			int ttx=tx+dir[i][0];
			int tty=ty+dir[i][1];
			if(ttx==ex&&tty==ey) return ts+1;
			if(ttx>8||tty>8||ttx<1||tty<1) continue;
			if(Map[ttx][tty]) continue;
			que.push(Node(ttx,tty,ts+1));
			Map[ttx][tty]=true;
		}
	}
	return -1;
}

int main(){
	char ss[5],es[5];
	while(~scanf("%s %s",ss,es)){
		memset(Map,false,sizeof(Map));
		if(strcmp(ss,es)==0){
			printf("To get from %s to %s takes 0 knight moves.\n",ss,es);
			continue;
		}
		int sx=ss[0]-'a'+1;
		int sy=ss[1]-'0';
		ex=es[0]-'a'+1;
		ey=es[1]-'0';
		int ans=bfs(sx,sy);
		printf("To get from %s to %s takes %d knight moves.\n",ss,es,ans);
	}
}
