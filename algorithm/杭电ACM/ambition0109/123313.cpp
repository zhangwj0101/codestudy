////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-08 10:14:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define M 105
#define INF 0x7fffffff

int Map[M][M],Min[M];
bool Hash[M];

int prim(int s,int n){
	for(int i=1;i<=n;i++){
		Min[i]=Map[s][i];
	}
	memset(Hash,false,sizeof(Hash));
	Hash[s]=true;
	int MVal=0,cnt=1;
	while(true){
		int tid=0,tcost=INF;
		for(int i=1;i<=n;i++){
			if(Hash[i]) continue;
			if(tcost>Min[i]){
				tcost=Min[i];
				tid=i;
			}
		}
		MVal+=tcost;
		Hash[tid]=true;
		if((cnt++)==n-1) break;
		for(int i=1;i<=n;i++){
			if(Hash[i]) continue;
			if(Min[i]>Map[tid][i]){
				Min[i]=Map[tid][i];
			}
		}
	}
	return MVal;
}

int main(){
    int n;
    while(scanf("%d",&n),n){
    	if(n==1){puts("0"); continue;}
        for(int i=0;i<n*(n-1)/2;i++){
            int u,v,val;
            scanf("%d%d%d",&u,&v,&val);
            Map[u][v]=Map[v][u]=val;
        }
        int Ans=prim(1,n);
        printf("%d\n",Ans);
    }
}
