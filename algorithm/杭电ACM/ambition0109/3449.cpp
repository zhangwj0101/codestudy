////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-23 16:21:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3449
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:21736KB
//////////////////System Comment End//////////////////
/*
 * 3449.cpp
 *
 *  Created on: 2010-9-23
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;

struct Items{
	int cost,val;
};
struct Kind{
	int n,cost;
	Items items[11];
}kind[55];

int Max(int a,int b)
{
	int dif=b-a;
	return b-(dif&(dif>>31));
}

int bag[55][100005];
int main()
{
	int n,v;
	while(scanf("%d%d",&n,&v)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d%d",&kind[i].cost,&kind[i].n);
			for(int j=0;j<kind[i].n;j++){
				scanf("%d%d",&kind[i].items[j].cost,&kind[i].items[j].val);
			}
		}
		memset(bag,-1,sizeof(bag));
		bag[0][0]=0;
		int max=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<kind[i].n;j++){
				for(int k=v;k>=0;k--){
					if(bag[i-1][k]!=-1){
						if(k+kind[i].items[j].cost+kind[i].cost<=v){
							bag[i][k+kind[i].items[j].cost+kind[i].cost]=
									Max(bag[i][k+kind[i].items[j].cost+kind[i].cost],
											bag[i-1][k]+kind[i].items[j].val);
						}
					}
					if(bag[i][k]!=-1){
						if(k+kind[i].items[j].cost<=v){
							bag[i][k+kind[i].items[j].cost]=
									Max(bag[i][k+kind[i].items[j].cost],
											bag[i][k]+kind[i].items[j].val);
						}
					}
				}
			}
			for(int k=0;k<=v;k++){
				bag[i][k]=Max(bag[i][k],bag[i-1][k]);
				if(bag[i][k]>max) max=bag[i][k];
			}
		}
		printf("%d\n",max);
	}
}
