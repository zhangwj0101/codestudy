////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-11 18:36:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1014
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:172KB
//////////////////System Comment End//////////////////
/*
 * 1014.cpp
 *
 *  Created on: 2010-8-11
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

inline int GCD(int x,int y)
{
	int i,j;
	if(x==0) return y;
	if(y==0) return x;
	for(i=0;0==(x&1);++i)x>>=1;
	for(j=0;0==(y&1);++j)y>>=1;
	if(j<i) i=j;
	while(1){
		if(x<y)x^=y,y^=x,x^=y;
		if(0==(x-=y)) return y<<i;
		while(0==(x&1))x>>=1;
	}
}

int main()
{
	int step,mod;
	while(scanf("%d%d",&step,&mod)!=EOF){
		printf("%10d%10d    ",step,mod);
		if(GCD(step,mod)==1){
			printf("Good Choice\n\n");
		}else{
			printf("Bad Choice\n\n");
		}
	}
}
