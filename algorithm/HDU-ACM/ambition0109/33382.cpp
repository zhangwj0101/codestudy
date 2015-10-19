////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-28 13:02:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3338
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:12464KB
//////////////////System Comment End//////////////////
/*
 * 3338.cpp
 *
 *  Created on: 2010-11-28
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 20010
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int lp,cap,next;
	Edge(int _lp=0,int _cap=0,int _next=0):
		lp(_lp),cap(_cap),next(_next){}
}E[999999];
int pre[M],cur[M],gap[M],dis[M];
int head[M],node,N;

void SAP(int s,int t){
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=0;i<N;i++){
		cur[i]=head[i];
	}
	int u=pre[s]=s,mf=INF;
	gap[0]=N;
	while(dis[s]<N){
		loop: for(int &i=cur[u];i!=-1;i=E[i].next){
			int v=E[i].lp;
			if(E[i].cap&&dis[u]==dis[v]+1){
				mf=MIN(mf,E[i].cap);
				pre[v]=u;
				u=v;
				if(v==t){
					for(u=pre[u];v!=s;v=u,u=pre[u]){
						E[cur[u]].cap-=mf;
						E[cur[u]^1].cap+=mf;
					}
					mf=INF;
				}
				goto loop;
			}
		}
		int mdis=N;
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].lp;
			if(E[i].cap&&mdis>dis[v]){
				cur[u]=i;
				mdis=dis[v];
			}
		}
		if((--gap[dis[u]])==0){
			break;
		}
		gap[dis[u]=mdis+1]++;
		u=pre[u];
	}
}

void Insert(int u,int v,int c){
	E[node]=Edge(v,c,head[u]);
	head[u]=node++;
	E[node]=Edge(u,0,head[v]);
	head[v]=node++;
}

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

int Map[105][105][2];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		Init();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char str[10];
				scanf("%s",str);
				if(str[0]=='.'){
					Map[i][j][0]=Map[i][j][1]=0;
				}else{
					if(str[0]=='X'){
						Map[i][j][0]=-1;
					}else{
						Map[i][j][0]=(str[0]-'0')*100+(str[1]-'0')*10+(str[2]-'0');
					}
					if(str[4]=='X'){
						Map[i][j][1]=-1;
					}else{
						Map[i][j][1]=(str[4]-'0')*100+(str[5]-'0')*10+(str[6]-'0');
					}
				}
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(Map[i][j][1]!=-1){
					int jj;
					for(jj=j+1;!Map[i][jj][1]&&jj<m;jj++){
						Insert((i*m+j)<<1,(i*m+jj)<<1,8);
					}
					Insert(n*m<<1,(i*m+j)<<1,Map[i][j][1]-(jj-j-1));
					j=jj-1;
				}
			}
		}
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				if(Map[i][j][0]!=-1){
					int ii;
					for(ii=i+1;!Map[ii][j][0]&&ii<n;ii++){
						Insert((ii*m+j)<<1,(i*m+j)<<1|1,8);
					}
					Insert((i*m+j)<<1|1,n*m<<1|1,Map[i][j][0]-(ii-i-1));
					i=ii-1;
				}
			}
		}

		N=n*m*2+2;
		SAP(n*m*2,n*m*2+1);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(j) printf(" ");
				if(Map[i][j][0]) printf("_");
				else printf("%d",9-E[head[(i*m+j)<<1]].cap);
			}
			puts("");
		}
	}
}
