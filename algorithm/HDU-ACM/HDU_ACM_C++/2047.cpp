////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-02 16:23:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,i,n;
	__int64 d[40][2]={{1,1},{1,2}};
	for(i=2;i<40;i++)
	{
		d[i][0]=d[i-1][1];
		d[i][1]=2*(d[i-1][0]+d[i-1][1]);
	}
	while(scanf("%d",&n)==1)
		printf("%I64d\n",d[n][1]+d[n][0]);
	return 0;
}