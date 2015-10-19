////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-28 14:57:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=100;

int n;
int Map[MAXN+1][MAXN+1];

void Init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			Map[i][j]=-(i!=j);
		}
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(Map[i][k]==-1||Map[k][j]==-1) continue;
				if(Map[i][j]==-1||Map[i][j]>Map[i][k]+Map[k][j]){
					Map[i][j]=Map[i][k]+Map[k][j];
				}
			}
		}
	}
}

int main()
{
	int m;
	while(scanf("%d%d",&n,&m),n||m){
		Init();
		for(int i=0;i<m;i++){
			int c1,c2,cost;
			scanf("%d%d%d",&c1,&c2,&cost);
			Map[c1][c2]=Map[c2][c1]=cost;
		}
		floyd();
		printf("%d\n",Map[1][n]);
	}
}
