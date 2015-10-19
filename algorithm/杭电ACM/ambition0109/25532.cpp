////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 20:39:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2553
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:180KB
//////////////////System Comment End//////////////////
/*
 * 2553.cpp
 *
 *  Created on: 2010-8-20
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

int num[11]={0,1,0,0,2,10,4,40,92,352,724};
int main()
{
	int n;
	while(scanf("%d",&n),n){
		printf("%d\n",num[n]);
	}
}