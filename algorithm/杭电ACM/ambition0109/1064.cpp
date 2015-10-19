////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-10 19:41:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:168KB
//////////////////System Comment End//////////////////
/*
 * 1064.cpp
 *
 *  Created on: 2010-7-10
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

int main()
{
	double sum=0;
	for(int i=0;i<12;i++){
		double num;
		scanf("%lf",&num);
		sum+=num;
	}
	printf("$%.2lf\n",sum/12.);
}
