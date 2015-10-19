////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-11 17:30:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1529
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

struct Edge{
	int u,v,w;
	Edge(){}
	Edge(int _u,int _v,int _w):
		u(_u),v(_v),w(_w){}
}edge[99999];
int dist[30],n,num[30],r[30],cnt;
void Make_G(int mid){
	cnt=0;
	for(int i=1;i<=24;++i){
		if(i>8) edge[cnt++]=Edge(i-8,i,-r[i]);
		else edge[cnt++]=Edge(i+16,i,mid-r[i]);
		edge[cnt++]=Edge(i-1,i,0);
		edge[cnt++]=Edge(i,i-1,num[i]);
	}
}
bool Bellman_Ford(){
	memset(dist,0x7f,sizeof(dist));
	dist[1]=0; bool flag;
	for(int j=0;j<=24;++j){
		flag=true;
		for(int i=0;i<cnt;++i){
			if(dist[edge[i].v]>dist[edge[i].u]+edge[i].w){
				dist[edge[i].v]=dist[edge[i].u]+edge[i].w;
				flag=false;
			}
		}
		if(flag) break;
	}
	return flag;
}

int main() {
	int i,k,ival;
	scanf("%d",&ival);
	while(ival--){
		for(i=1;i<=24;++i)scanf("%d",&r[i]);
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		for(i=1;i<=n;++i){
			scanf("%d",&k);
			num[k+1]++;
		}
		int low=1,high=n,mid=n/2,ans=-1;
		while(low<=high){
			Make_G(mid);
			if(Bellman_Ford()){
				high=(ans=mid)-1;
			}else low=mid+1;
			mid=(low+high)>>1;
		}
		if(ans==-1||n==4)printf("No Solution\n");
		else printf("%d\n",ans);
	}
	return 0;
}