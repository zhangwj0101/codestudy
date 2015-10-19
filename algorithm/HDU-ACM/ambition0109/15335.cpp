////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-10 19:56:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1533
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:556KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

struct Pos{
	int x,y;
}H[105],M[105];

int map[205][205],cost[205][205];
int pre[205],dis[205];
int que[9999999],nn;
bool Hash[205];

int Min(const int& a,const int& b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

int Abs(const int& a){
	int temp=(a>>31);
	return (a+temp)^temp;
}

bool SPFA(int s,int t){
	memset(dis,0x7f,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	memset(Hash,false,sizeof(Hash));
	dis[s]=0;
	que[0]=s;
	int qs=0,qe=0;
	while(qs<=qe){
		int u=que[qs++];
		Hash[u]=false;
		for(int i=0;i<nn;i++){
			if(map[u][i]&&dis[u]+cost[u][i]<dis[i]){
				dis[i]=dis[u]+cost[u][i];
				if(!Hash[i]){
					que[++qe]=i;
					Hash[i]=true;
				}
				pre[i]=u;
			}
		}
	}
	if(pre[t]!=-1) return true;
	else return false;
}

int MCF(int s,int t){
	int Sum=0;
	while(SPFA(s,t)){
		int k=t;
		while(k!=s){
			map[pre[k]][k]-=1;
			map[k][pre[k]]+=1;
			k=pre[k];
		}
		Sum+=dis[t];
	}
	return Sum;
}

int main(){
	char str[105];
	int c,r;
	while(scanf("%d%d",&c,&r),c||r){
		memset(map,0,sizeof(map));
		memset(cost,0,sizeof(cost));
		int h=0,m=0;
		for(int i=0;i<c;i++){
			scanf("%s",str);
			for(int j=0;j<r;j++){
				if(str[j]=='H'){
					H[h].x=i;
					H[h++].y=j;
				}else if(str[j]=='m'){
					M[m].x=i;
					M[m++].y=j;
				}
			}
		}
		int n=h;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j+n]=1;
				cost[i][j+n]=Abs(int(H[i].x-M[j].x))+Abs(int(H[i].y-M[j].y));
				cost[j+n][i]=-cost[i][j+n];
			}
		}
		for(int i=0;i<n;i++){
			map[2*n][i]=1;
			map[i+n][2*n+1]=1;
		}
		nn=n*2+2;
		int Ans=MCF(2*n,2*n+1);
		printf("%d\n",Ans);
	}
}
