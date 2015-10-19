////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-20 18:17:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3466
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<iostream>
#include<memory>
using namespace std;

int bag[5001];
struct Goods{
	int vl;
	int vr;
	int w;
};
int compare(const void* a,const void* b){
	return ((*(Goods*)a).vr-(*(Goods*)a).vl)-((*(Goods*)b).vr-(*(Goods*)b).vl);
}
Goods goods[501];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&goods[i].vl,&goods[i].vr,&goods[i].w);
		qsort(goods+1,n,sizeof(Goods),compare);
		memset(bag,0,sizeof(int)*(m+1));
		for(int i=1;i<=n;i++){
			for(int j=m;j>=goods[i].vr;j--)
				if(bag[j-goods[i].vl]+goods[i].w>bag[j])
					bag[j]=bag[j-goods[i].vl]+goods[i].w;
		}
		printf("%d\n",bag[m]);
	}
}