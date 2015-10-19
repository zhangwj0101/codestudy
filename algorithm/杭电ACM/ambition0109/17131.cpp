////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 20:27:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1713
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:156KB
//////////////////System Comment End//////////////////
/*
 * 1713.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

long long GCD(long long a,long long b)
{
	if(b>a){
		long long t=a;a=b;b=t;
	}
	while(b)
	{
		long long t=b;
		b=a%b;
		a=t;
	}
	return a;
}
int main()
{
	long long a1,b1,a2,b2,aa,bb,g;
	int t;
	for(scanf("%d",&t);t--;)
	{
		scanf("%I64d/%I64d %I64d/%I64d",&a1,&b1,&a2,&b2);
		aa=b1*b2;
		bb=a1*b2/GCD(a1*b2,a2*b1)*b1*a2;
		g=GCD(bb,aa);
		if(aa==g) printf("%I64d\n",bb/g);
		else printf("%I64d/%I64d\n",bb/g,aa/g);
	}
	return 0;
}
