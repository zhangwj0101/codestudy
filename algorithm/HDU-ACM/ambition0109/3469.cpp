////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-22 17:04:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3469
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<string>
#include<memory>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
	int n,t;int c=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("Case %d: ",c++);
		if(n==1) printf("1");
		else if(n==2) printf("2");
		else printf("%d",2*n-4);
		printf("\n");
	}
}