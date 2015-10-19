////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 18:26:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2085
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	__int64 H[34]={1},L[34]={0};
	int i,n;
	for(i=1;i<34;i++)
	{
		H[i]=3*H[i-1]+2*L[i-1];
		L[i]=H[i-1]+L[i-1];
	}
	while((cin>>n)&&(n>=0))
		printf("%I64d, %I64d\n",H[n],L[n]);
   return 0;
}