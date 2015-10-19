////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-30 10:27:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2807
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:2696KB
//////////////////System Comment End//////////////////
/*
 * 2807.cpp
 *
 *  Created on: 2010-9-29
 *      Author: administrator
 */

#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define MaxN 85

struct Matrix{
	int Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
}Mat[85];
int Size;

vector<vector<int> > Graph;
int Path[MaxN+1];
struct CMP{
	bool operator() (const int& a,const int& b){
		return Path[a]>Path[b];
	}
};

void Init(int n){
	Graph.clear();
	Graph.resize(n+1);
	memset(Path,-1,sizeof(Path));
}

int Dijkstra(int START,int END){
	priority_queue<int,vector<int>,CMP> QUE;
	Path[START]=0;
	QUE.push(START);
	while(!QUE.empty()){
		int Ups=QUE.top();
		if(Ups==END) return Path[Ups];
		QUE.pop();
		for(unsigned i=0;i<Graph[Ups].size();i++){
			int tCity=Graph[Ups][i];
			if(Path[tCity]==-1||Path[Ups]+1<Path[tCity]){
				Path[tCity]=Path[Ups]+1;
				QUE.push(tCity);
			}
		}
	}
	return -1;
}

Matrix MMul(const Matrix& A,const Matrix& B){
	Matrix Ans;
	for(int i=1;i<=Size;i++){
		for(int x=1;x<=Size;x++){
			if(!A.Mat[x][i]) continue;
			for(int y=1;y<=Size;y++){
				if(!B.Mat[i][y]) continue;
				Ans.Mat[x][y]+=A.Mat[x][i]*B.Mat[i][y];
			}
		}
	}
	return Ans;
}

bool MEQU(const Matrix& A,const Matrix& B){
	for(int i=1;i<=Size;i++){
		for(int j=1;j<=Size;j++){
			if(A.Mat[i][j]!=B.Mat[i][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		Init(n);
		Size=m;
		for(int i=1;i<=n;i++){
			for(int x=1;x<=m;x++){
				for(int y=1;y<=m;y++){
					scanf("%d",&Mat[i].Mat[x][y]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				Matrix tmp=MMul(Mat[i],Mat[j]);
				for(int k=1;k<=n;k++){
					if(i==k||j==k) continue;
					if(MEQU(Mat[k],tmp)){
						Graph[i].push_back(k);
					}
				}
			}
		}
		int k;
		scanf("%d",&k);
		while(k--){
			int s,e,c;
			scanf("%d%d",&s,&e);
			memset(Path,-1,sizeof(Path));
			c=Dijkstra(s,e);
			if(c==-1){
				puts("Sorry");
			}else{
				printf("%d\n",c);
			}
		}
	}
}






















