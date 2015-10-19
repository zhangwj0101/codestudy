////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-02 16:10:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2048
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
	__int64 d[21][2]={{1,1},{1,0},{2,1}};
	for(i=3;i<21;i++)
	{
		d[i][0]=i*d[i-1][0];
		d[i][1]=(i-1)*(d[i-1][1]+d[i-2][1]);
	}
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		printf("%.2lf%%\n",d[n][1]*100.0/d[n][0]);
	}
	return 0;
}