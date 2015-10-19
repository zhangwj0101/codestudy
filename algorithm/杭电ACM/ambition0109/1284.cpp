////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-03 15:18:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1284
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:420KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int num[32768];
void main()
{
	int n,i;
	num[0]=1;
	for(i=1;i<32768;i++)
		num[i]+=num[i-1];
	for(i=2;i<32768;i++)
		num[i]+=num[i-2];
	for(i=3;i<32768;i++)
		num[i]+=num[i-3];
	while(cin>>n)
		printf("%d\n",num[n]);
}