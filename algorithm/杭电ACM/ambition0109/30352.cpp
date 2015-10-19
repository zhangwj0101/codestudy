////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-18 11:48:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3035
////Problem Title: 
////Run result: Accept
////Run time:953MS
////Run memory:47068KB
//////////////////System Comment End//////////////////
/*
 * 3035.cpp
 *
 *  Created on: 2010-12-18
 *      Author: amb
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define M 1500000

inline void in(int &num)
{
	char in;
	in=getchar();
	while(in<'0'||in>'9'){
		in=getchar();
	}
	num=in-'0';
	in=getchar();
	while(in>='0'&&in<='9'){
		num*=10;num+=in-'0';
		in=getchar();
	}
}


struct Edge{
	int id,val,next;
}E[3000000];
int head[M],node;
int cost[M];

struct cmp{
	bool operator() (const int& a,const int& b){
		return cost[a]>cost[b];
	}
};

int Dijkstra(int s,int e){
	memset(cost,0x7f,sizeof(cost));
	priority_queue<int,vector<int>,cmp> que;
	cost[s]=0;
	que.push(s);
	while(!que.empty()){
		int u=que.top(); que.pop();
		if(u==e) return cost[e];
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].id;
			if(cost[u]+E[i].val<cost[v]){
				cost[v]=E[i].val+cost[u];
				que.push(v);
			}
		}
	}
	return -1;
}

void Insert(int u,int v,int c){
	E[node].id=v;
	E[node].val=c;
	E[node].next=head[u];
	head[u]=node++;
}

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int s=n*m<<2,t=(n*m<<2)+1,tmp;
		Init();

		for(int mm=0;mm<m;mm++){
			in(tmp);
			Insert(s,mm<<2,tmp);
		}
		for(int nn=0;nn<n-1;nn++){
			for(int mm=0;mm<m;mm++){
				in(tmp);
				Insert(((nn*m+mm)<<2)+2,((nn+1)*m+mm)<<2,tmp);
				Insert(((nn+1)*m+mm)<<2,((nn*m+mm)<<2)+2,tmp);
			}
		}
		for(int mm=0;mm<m;mm++){
			in(tmp);
			Insert((((n-1)*m+mm)<<2)+2,t,tmp);
		}

		for(int nn=0;nn<n;nn++){
			in(tmp);
			Insert(((nn*m)<<2)+1,t,tmp);
			for(int mm=0;mm<m-1;mm++){
				in(tmp);
				Insert(((nn*m+mm)<<2)+3,((nn*m+mm+1)<<2)+1,tmp);
				Insert(((nn*m+mm+1)<<2)+1,((nn*m+mm)<<2)+3,tmp);
			}
			in(tmp);
			Insert(s,((nn*m+m-1)<<2)+3,tmp);
		}

		for(int nn=0;nn<n;nn++){
			for(int mm=0;mm<m;mm++){
				in(tmp);
				Insert(((nn*m+mm)<<2)+1,(nn*m+mm)<<2,tmp);
				Insert(((nn*m+mm)<<2),((nn*m+mm)<<2)+1,tmp);
				in(tmp);
				Insert(((nn*m+mm)<<2)+3,(nn*m+mm)<<2,tmp);
				Insert(((nn*m+mm)<<2),((nn*m+mm)<<2)+3,tmp);
			}
			for(int mm=0;mm<m;mm++){
				in(tmp);
				Insert(((nn*m+mm)<<2)+1,((nn*m+mm)<<2)+2,tmp);
				Insert(((nn*m+mm)<<2)+2,((nn*m+mm)<<2)+1,tmp);
				in(tmp);
				Insert(((nn*m+mm)<<2)+3,((nn*m+mm)<<2)+2,tmp);
				Insert(((nn*m+mm)<<2)+2,((nn*m+mm)<<2)+3,tmp);
			}
		}

		printf("%d\n",Dijkstra(s,t));
	}

}
