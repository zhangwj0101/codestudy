////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-03 09:25:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2393
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define P(x) x*x
int main()
{
	int tt,t,i,k;
	vector<int> a;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		a.clear();
		for(i=0;i<3;i++)
		{
			scanf("%d",&tt);
			a.push_back(tt);
		}
		sort(a.begin(),a.end());
		printf("Scenario #%d:\n%s\n\n",k,P(a[0])+P(a[1])==P(a[2])?"yes":"no");
	}
	return 0;
}