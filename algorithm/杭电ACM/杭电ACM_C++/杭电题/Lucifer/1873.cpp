////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-22 10:56:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1873
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <algorithm>
#include <queue>
using namespace std;
struct REC
{
	int priority;
	int id;
};
bool cmp(REC a,REC b)
{
	if(a.priority!=b.priority)
	{
		return a.priority>b.priority;
	}
	else
	{
		return a.id<b.id;
	}
}
int main( )
{
	int a,b;
	int k;
	char str[4];
	REC temp;
	int n,i;
	vector<REC> q[4];
	while(scanf("%d",&n)!=EOF)
	{
		k=0;
		for(i=1;i<4;i++)
		{
			q[i].clear();
		}

		while(n--)
		{
			scanf("%s",str);
			if(!strcmp(str,"IN"))
			{
				scanf("%d%d",&a,&b);
				temp.priority=b;
				temp.id=++k;
				q[a].push_back(temp);
				sort(q[a].begin(),q[a].end(),cmp);
			}
			else
			{
				scanf("%d",&a);
				if(!q[a].empty())
				{
					printf("%d\n",q[a].front().id);
					q[a].erase(q[a].begin());
				}
				else
					puts("EMPTY");
			}
		}
	}
	return 0;

}