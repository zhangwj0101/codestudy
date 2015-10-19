////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-27 11:48:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1175
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2168KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

inline bool scan_ud(int &num)
{
	char in;
	in=getchar();
	if(in==EOF) return false;
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	return true;
}

int ax,ay,sx,sy,ex,ey;
int map[1001][1001];
int Dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool Dfs(int x,int y,int t,int dir)
{
	if(t==0);
	else if(t==1){
		if(ex>x&&dir==2) return false;
		if(ex<x&&dir==0) return false;
		if(ey>y&&dir==3) return false;
		if(ey<y&&dir==1) return false;
	}else if(t==2){
		if(ex>x&&dir!=0) return false;
		if(ex<x&&dir!=2) return false;
		if(ey>y&&dir!=1) return false;
		if(ey<y&&dir!=3) return false;
	}else return false;
	if(x==ex&&y==ey) return true;
	for(int i=0;i<4;i++){
		int tx=x+Dir[i][0],ty=y+Dir[i][1];
		if(tx>=0&&tx<ax&&ty>=0&&ty<ay){
			if(map[ty][tx]==map[sy][sx]){
				if(ty!=ey||tx!=ex) continue;
			}
			else if(map[ty][tx]) continue;
			if(dir==i+2||dir==i-2) continue;
			else if(dir==i){
				if(Dfs(tx,ty,t,i)) return true;
			}else{
				if(Dfs(tx,ty,t+1,i)) return true;
			}
		}
	}
	return false;
}

int main()
{
	while(scan_ud(ay)&&scan_ud(ax),ay||ax){
		for(int i=0;i<ay;i++)
			for(int j=0;j<ax;j++)
				scan_ud(map[i][j]);
		int T;
		scan_ud(T);
		while(T--){
			scan_ud(sy);sy--;
			scan_ud(sx);sx--;
			scan_ud(ey);ey--;
			scan_ud(ex);ex--;
			if(map[sy][sx]!=map[ey][ex]||map[sy][sx]==0){
				printf("NO\n");
				continue;
			}
			if(sx==ex&&sy==ey){
				printf("YES\n");
				continue;
			}
			bool tof=false;
			for(int i=0;i<4;i++){
				int tx=sx+Dir[i][0],ty=sy+Dir[i][1];
				if(tx==ex&&ty==ey){tof=true;break;}
				if(tx>=0&&tx<ax&&ty>=0&&ty<ay){
					if(map[ty][tx]) continue;
					if(Dfs(tx,ty,0,i))
						tof=true;
				}
				if(tof) break;
			}
			if(tof) printf("YES\n");
			else printf("NO\n");
		}
	}
}