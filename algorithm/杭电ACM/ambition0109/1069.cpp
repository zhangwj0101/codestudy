////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-22 16:39:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1069
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*
 * 1069.cpp
 *
 *  Created on: 2010-10-22
 *      Author: administrator
 */

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Box{
	int a,b,c;
	void set(int na,int nb,int nc){
		a=na,b=nb,c=nc;
	}
}box[100];

struct Q{
	int w,h;
};

bool cmp(const Box& a,const Box& b){
	if(a.a==b.a) return a.b>b.b;
	return a.a<b.a;
}
vector<Q> Que;

int main(){
	int n,cas=0;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			int a[3];
			scanf("%d%d%d",&a[0],&a[1],&a[2]);
			sort(a,a+3);
			box[i*3].set(a[0],a[1],a[2]);
			box[i*3+1].set(a[1],a[2],a[0]);
			box[i*3+2].set(a[0],a[2],a[1]);
		}
		Que.clear();
		sort(box,box+n*3,cmp);
		Q tmp; int len=1,max=0;
		tmp.h=0; tmp.w=0;
		Que.push_back(tmp);
		for(int i=0;i<n*3;i++){
			int tmax=0;
			for(int j=0;j<len;j++){
				if(box[i].b>Que[j].w){
					if(Que[j].h+box[i].c>tmax){
						tmax=Que[j].h+box[i].c;
					}
				}
			}
			if(tmax>max) max=tmax;
			tmp.w=box[i].b;
			tmp.h=tmax;
			Que.push_back(tmp);
			len++;
		}
		printf("Case %d: maximum height = %d\n",++cas,max);
	}
}
