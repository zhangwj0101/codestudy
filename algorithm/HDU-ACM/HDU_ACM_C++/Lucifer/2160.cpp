////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 15:43:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2160
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int z[21]={1,1};
int main()
{
	int t,i,m;
	cin>>t;
	for(i=2;i<21;i++)
		z[i]=z[i-1]+z[i-2];
	while(t--)
	{
		scanf("%d",&m);
		printf("%d\n",z[m]);
	}
	return 0;
}