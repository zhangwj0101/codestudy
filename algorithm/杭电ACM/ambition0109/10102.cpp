////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-23 17:26:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;

int ax,ay;int sx,sy,ex,ey;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char map[8][8];

bool Dfs(int x,int y,int t)
{
	if(x==ex&&y==ey&&t==0) return true;
	if(t<abs(ex-x)+abs(ey-y)||t<=0) return false;
	for(int i=0;i<4;i++){
		int tx=x+dir[i][0],ty=y+dir[i][1];
		if(tx>=0&&tx<ax&&ty>=0&&ty<ay)
			if(map[ty][tx]!='X'){
			map[ty][tx]='X';
			if(Dfs(tx,ty,t-1)) return true;
			map[ty][tx]='.';
		}
	}
	return false;
}

void main()
{
	int t;
	while(cin>>ax>>ay>>t,ax||ay||t){
		for(int i=0;i<ay;i++){
			for(int j=0;j<ax;j++){
				cin>>map[i][j];
				if(map[i][j]=='S'){
					sx=j,sy=i;
					map[i][j]='X';
				}else if(map[i][j]=='D'){
					ex=j,ey=i;
					map[i][j]='.';
				}
			}
		}
		if((t+abs(ex-sx)+abs(ey-sy))&1){
			cout<<"NO"<<endl;
			continue;
		}
		if(Dfs(sx,sy,t)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}