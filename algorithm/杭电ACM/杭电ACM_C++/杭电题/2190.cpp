////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-13 17:09:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2190
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int a[31]={1,1};
int main()
{
	int n,i,m;
	for(i=2;i<=30;i++)
		a[i]=a[i-1]+2*a[i-2];
	cin>>n;
	while(n--)
	{
		scanf("%d",&m);
		printf("%d\n",a[m]);
	}
	return 0;
}