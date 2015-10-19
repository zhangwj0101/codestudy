////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-12 16:29:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2095
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<set>
using namespace std;

void main()
{
	int n,temp;
	set<int> num;
	while(scanf("%d",&n),n)
	{
		num.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(num.count(temp)) num.erase(temp);
			else num.insert(temp);
		}
		cout<<*num.begin()<<endl;
	}
}