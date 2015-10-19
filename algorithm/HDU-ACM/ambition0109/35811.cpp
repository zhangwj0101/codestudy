////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-10 08:56:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3581
////Problem Title: 
////Run result: Accept
////Run time:578MS
////Run memory:1988KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Seg{
	int l,r;
}seg[100005];

bool cmp(const Seg& a,const Seg& b){
	return a.r<b.r;
}

int point[505];
int Ans[505][505];
int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d%d",&seg[i].l,&seg[i].r);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&point[i]);
		}
		memset(Ans,0,sizeof(Ans));
		for(int i=0;i<n;i++){
			if(seg[i].l>point[m-1]) continue;
			if(seg[i].r<point[0]) continue;
			int x,y;
			for(int j=0;j<m;j++){
				if(seg[i].l<=point[j]){
					x=j;
					break;
				}
			}
			for(int j=m-1;j>=0;j--){
				if(seg[i].r>=point[j]){
					y=j;
					break;
				}
			}
			Ans[x][y]++;
		}
		for(int i = 0; i <m-1; i++)
		{
			for(int j = m-1; j > i; j--)
			{
				Ans[i][j-1]+=Ans[i][j];
				Ans[i+1][j]+= Ans[i][j];
				Ans[i+1][j-1]-= Ans[i][j];
				Ans[j][i] = Ans[i][j];
			}
		}
		printf("Case %d:\n",++cas);
		for(int i=0;i<m;i++){
			printf("%d",Ans[i][0]);
			for(int j=1;j<m;j++){
				printf(" %d",Ans[i][j]);
			}
			puts("");
		}
		puts("");
	}
}