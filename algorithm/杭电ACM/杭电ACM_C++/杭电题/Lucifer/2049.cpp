////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-02 16:33:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2049
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,i,n,m;
	__int64 d[21][2]={{1,1},{1,0},{2,1}};
	for(i=3;i<21;i++)
	{
		d[i][0]=i*d[i-1][0];
		d[i][1]=(i-1)*(d[i-1][1]+d[i-2][1]);
	}
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%I64d\n",d[n][0]/d[m][0]/d[n-m][0]*d[m][1]);
	}
	return 0;
}