////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-15 15:41:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3687
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ABS(x) (x<0?-x:x)
#define INF 0x7fffffff

int pos[60][60],rp[60];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		int mmin=200,mmax=0;
		memset(rp,0,sizeof(rp));
		for(int i=0;i<n*n;i++){
			int c,r;
			scanf("%d%d",&c,&r);
			pos[c][rp[c]++]=r;
			if(mmin>r) mmin=r;
			if(mmax<r) mmax=r;
		}
		for(int i=1;i<=n;i++) sort(pos[i],pos[i]+n);
		int Ans=INF;
		for(int i=mmin;i<=mmax-n+1;i++){
			int tmp=0;
			for(int j=1;j<=n;j++){
				for(int k=0;k<n;k++){
					tmp+=ABS((pos[j][k]-(i+k)));
				}
			}
			if(tmp<Ans) Ans=tmp;
		}
		printf("%d\n",Ans);
	}
}
