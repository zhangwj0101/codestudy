////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-02 16:43:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2189
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
			53,59,61,67,71,73,79,83,89,97,101,103,107,
			109,113,127,131,137,139,149};
int num[151];
void main()
{
	int n,i,j,m;
	memset(num,0,sizeof(num));
	num[0]=1;
	for(i=0;i<35;i++)
	{
		j=0;
		while(j+prime[i]<=150)
		{
			num[j+prime[i]]+=num[j];
			j++;
		}
	}
	for(cin>>n;n>0;n--)
	{
		cin>>m;
		cout<<num[m]<<endl;
	}
}