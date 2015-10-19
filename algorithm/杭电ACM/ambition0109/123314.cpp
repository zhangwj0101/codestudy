////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-08 10:34:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:272KB
//////////////////System Comment End//////////////////
/*
 * prim.cpp
 *
 *  Created on: 2010-11-25
 *      Author: hduacm
 */

//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<vector>
//using namespace std;
//#define M 105
//#define MIN(x,y) (x>y?y:x)
//
//struct Edge{
//	int id,val;
//	Edge(){}
//	Edge(int i,int v):id(i),val(v){}
//	friend bool operator <(const Edge& a,const Edge& b){
//		return a.val>b.val;
//	}
//};
//int Map[M][M];
//bool Hash[M];
//
//int prim(int s,int n){
//	int MVal=0,cnt=0;
//	memset(Hash,false,sizeof(Hash));
//	priority_queue<Edge,vector<Edge> > que;
//	que.push(Edge(s,0));
//	while(!que.empty()){
//		Edge medge=que.top();que.pop();
//		if(Hash[medge.id]) continue;
//		Hash[medge.id]=true;
//		MVal+=medge.val;
//		cnt++;
//		if(cnt==n) return MVal;
//		for(int i=1;i<=n;i++){
//			if(Hash[i]) continue;
//			que.push(Edge(i,Map[medge.id][i]));
//		}
//	}
//	return -1;
//}


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define M 105
#define INF 0x7fffffff

int Map[M][M],Min[M];
bool Hash[M];

void Init(){
	memset(Map,-1,sizeof(Map));

}

int prim(int s,int n){
	if(n==1) return 0;
	for(int i=1;i<=n;i++){
		Min[i]=Map[s][i];
	}
	memset(Hash,false,sizeof(Hash));
	Hash[s]=true;
	int MVal=0,cnt=0;
	while(true){
		int tid=-1,tcost=INF;
		for(int i=1;i<=n;i++){
			if(Hash[i]) continue;
			if(Min[i]!=-1&&tcost>Min[i]){
				tcost=Min[i];
				tid=i;
			}
		}
		if(tid==-1) return -1;
		MVal+=tcost;
		Hash[tid]=true;
		for(int i=1;i<=n;i++){
			if(Hash[i]) continue;
			if(Map[tid][i]!=-1&&(Min[i]==-1||Min[i]>Map[tid][i])){
				Min[i]=Map[tid][i];
			}
		}
		if((++cnt)==n-1) break;
	}
	return MVal;
}


int main(){
    int n;
    while(scanf("%d",&n),n){
    	Init();
        for(int i=0;i<n*(n-1)/2;i++){
            int u,v,val;
            scanf("%d%d%d",&u,&v,&val);
            Map[u][v]=Map[v][u]=val;
        }
        int Ans=prim(1,n);
        printf("%d\n",Ans);
    }
}
