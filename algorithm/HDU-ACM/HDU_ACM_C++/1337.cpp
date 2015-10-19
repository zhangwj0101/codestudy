////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-23 15:51:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1337
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,j,m;
	bool a[101]={0};
	int b[101];
	cin>>n;
	for(i=2;i<101;i++)
	{
		for(j=i;j<101;j+=i)
		{
			a[j]=(a[j]?0:1);
		}
	}
	b[4]=2;
	for(i=5;i<101;i++)
	{
		b[i]=b[i-1]+!a[i];
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		printf("%d\n",b[m]);
	}
	return 0;
}