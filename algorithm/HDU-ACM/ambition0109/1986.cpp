////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-08 15:13:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1986
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int Map[25][25];
int dxy[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void GetMap(char str[],int n,int m){
	memset(Map,-1,sizeof(Map));
	int x=1,y=1,dir=0;
	int len=strlen(str);
	for(int i=0;i<len;i++){
		int t;
		if(str[i]==' ') t=0;
		else t=str[i]-'A'+1;
		for(int j=16;j;j>>=1){
			if(t&j) Map[x][y]=1;
			else Map[x][y]=0;
			int tx=x+dxy[dir][0];
			int ty=y+dxy[dir][1];
			if(tx>n||ty>m||tx<1||ty<1||Map[tx][ty]!=-1){
				dir=(dir+1)%4;
			}
			x+=dxy[dir][0];
			y+=dxy[dir][1];
		}
	}
}

int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		int n,m;
		char str[100];
		scanf("%d %d",&n,&m);
		getchar();
		gets(str);
		GetMap(str,m,n);
		printf("%d ",++cas);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(Map[j][i]==-1) Map[j][i]=0;
				printf("%d",Map[j][i]);
			}
		}
		puts("");
	}
}