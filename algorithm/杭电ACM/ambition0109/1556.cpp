////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 18:27:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:540KB
//////////////////System Comment End//////////////////
/*
 * 1556.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

int num[100002];
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		for(int i=1;i<=n;i++)
			num[i]=0;
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			num[a]++;num[b+1]--;
		}
		int tt=0;
		for(int i=1;i<=n;i++)
		{
			tt+=num[i];
			if(i!=1) printf(" ");
			printf("%d",tt);
		}
		printf("\n");
	}
	return 0;
}
