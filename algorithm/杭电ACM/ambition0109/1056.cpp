////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-26 13:09:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1056
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

double num[300];
void main()
{
	int i;
	num[0]=0;
	for(i=1;i<300;i++)
		num[i]=num[i-1]+1./(double)(i+1.);
	double n;
	while(scanf("%lf",&n),n)
	{
		i=0;
		while(n>num[i])
			i++;
		printf("%d card(s)\n",i);
	}
}