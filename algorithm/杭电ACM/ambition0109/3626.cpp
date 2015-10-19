////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-12 19:52:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3626
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;

struct Unit{
	int r,c;
};
int n;
Unit unit[1005],dis[1005];
bool cmp(const Unit& a,const Unit& b){
	if(a.r==b.r) return a.c<b.c;
	else return a.r<b.r;
}

int find(int val){
	int top=0,bot=n-1;
	int mid=(top+bot)>>1;
	int ans=mid;
	while(top<=bot){
		if(dis[mid].r>=val){
			bot=(ans=mid)-1;
		}else{
			top=mid+1;
		}
		mid=(top+bot)>>1;
	}
	return ans;
}

int main()
{
	int c=0;
	while(scanf("%d",&n),n){
		if(c){
			puts("");
		}
		printf("Case %d:\n",++c);
		for(int i=0;i<n;i++){
			scanf("%d%d",&unit[i].r,&unit[i].c);
			dis[i].r=unit[i].r;
			dis[i].c=unit[i].c;
		}
		sort(dis,dis+n,cmp);
		for(int i=0;i<n;i++){
			int p=find(unit[i].r);
			int t;
			for(t=p+1;t<n;t++){
				if(dis[t].r>unit[i].r&&dis[t].c>unit[i].c){
					break;
				}
			}
			if(t==n){
				puts("-1 -1");
			}else{
				printf("%d %d\n",dis[t].r,dis[t].c);
			}
		}
	}
}