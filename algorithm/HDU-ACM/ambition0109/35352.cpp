////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-23 14:37:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3535
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:324KB
//////////////////System Comment End//////////////////
/*
 * 3535.cpp
 *
 *  Created on: 2010-9-23
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Items{
	int cost,val;
};
bool cmpr(const Items& a,const Items& b){
	return a.cost>b.cost;
}
struct Kind{
	int n,t;
	Items items[105];
	void Sort(){
		sort(items,items+n,cmpr);
	}
}kind[105];

bool cmp(const Kind& a,const Kind& b){
	return a.t>b.t;
}

int Max(int a, int b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

int bag[105][105];
int main()
{
	int n,t;
	while(scanf("%d%d",&n,&t)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d%d",&kind[i].n,&kind[i].t);
			for(int j=0;j<kind[i].n;j++){
				scanf("%d%d",&kind[i].items[j].cost,&kind[i].items[j].val);
			}
			kind[i].Sort();
		}
		memset(bag,-1,sizeof(bag));
		sort(kind+1,kind+n+1,cmp);
		bag[0][0]=0;
		for(int i=1;i<=n;i++){
			if(kind[i].t==0){
				for(int j=0;j<kind[i].n;j++){
					for(int k=t;k>=kind[i].items[j].cost;k--){
						if(bag[i][k-kind[i].items[j].cost]!=-1){
							bag[i][k]=Max(bag[i][k],
									bag[i][k-kind[i].items[j].cost]+kind[i].items[j].val);
						}
						if(bag[i-1][k-kind[i].items[j].cost]!=-1){
							bag[i][k]=Max(bag[i][k],
									bag[i-1][k-kind[i].items[j].cost]+kind[i].items[j].val);
						}
					}
				}
			}else if(kind[i].t==1){
				for(int j=0;j<kind[i].n;j++){
					for(int k=t;k>=0;k--){
						if(k>=kind[i].items[j].cost){
							if(bag[i-1][k-kind[i].items[j].cost]!=-1){
								bag[i][k]=Max(bag[i][k],
										bag[i-1][k-kind[i].items[j].cost]+kind[i].items[j].val);
							}
						}
						bag[i][k]=Max(bag[i][k],bag[i-1][k]);
					}
				}
			}else if(kind[i].t==2){
				for(int j=0;j<kind[i].n;j++){
					for(int k=t;k>=0;k--){
						if(k>=kind[i].items[j].cost){
							if(bag[i][k-kind[i].items[j].cost]!=-1){
								bag[i][k]=Max(bag[i][k],
									bag[i][k-kind[i].items[j].cost]+kind[i].items[j].val);
							}
							if(bag[i-1][k-kind[i].items[j].cost]!=-1){
								bag[i][k]=Max(bag[i][k],
										bag[i-1][k-kind[i].items[j].cost]+kind[i].items[j].val);
							}
						}
						bag[i][k]=Max(bag[i][k],bag[i-1][k]);
					}
				}
			}
		}
		int max=-1;
		for(int i=0;i<=t;i++){
			if(bag[n][i]>max){
				max=bag[n][i];
			}
		}
		printf("%d\n",max);
	}
}
