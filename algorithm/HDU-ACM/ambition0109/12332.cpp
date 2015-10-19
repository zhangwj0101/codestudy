////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-10 19:31:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*
 * 1233.cpp
 *
 *  Created on: 2010-8-10
 *      Author: ambition
 */

#include<cstdio>
#include<algorithm>
using namespace std;
#include<memory.h>

struct Road{
	int c1,c2,cost;
};
bool compare(const Road& a,const Road& b){
	if(a.cost<b.cost) return true;
	return false;
}
Road road[5051];
int city[101];
int Find(int n) {
	if(city[n]==-1) return n;
	return city[n]=Find(city[n]);
}
bool Merge(int s1,int s2)
{
	int r1=Find(s1);
	int r2=Find(s2);
	if(r1==r2) return false;
	if(r1<r2) city[r2]=r1;
	else city[r1]=r2;
	return true;
}
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int m=n*(n-1)/2;
		memset(city,-1,sizeof(city));
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&road[i].c1,&road[i].c2,&road[i].cost);
		}
		sort(road,road+m,compare);
		int sum=0,count=0;
		for(int i=0;i<m;i++){
			if(Merge(road[i].c1,road[i].c2)){
				count++;sum+=road[i].cost;
			}
			if(count==n-1)
				break;
		}
		printf("%d\n",sum);
	}
}
