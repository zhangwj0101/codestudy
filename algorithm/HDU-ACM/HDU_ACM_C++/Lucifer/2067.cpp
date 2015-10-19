////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-02 17:20:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2067
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int k=0,i,j,n;
	__int64 a[36]={1};
	__int64 b[36]={0};
	for(i=1;i<36;i++)
	{
		for(j=1;j<i;j++)
			a[j]+=a[j-1];
		b[i]=a[i]=a[i-1];
	}
	while(scanf("%d",&n),n+1)
	{
		printf("%d %d %I64d\n",++k,n,2*b[n]);
	}
	return 0;
}