////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-29 17:15:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:875MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int q[100002];
int main()
{
	int i,n,a,b,s;
	while(scanf("%d",&n),n)
	{
		memset(q,0,n*4+4);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			q[a]++,q[b+1]--;
		}
		for(s=0,i=1;i<=n;i++)
		{
			s+=q[i];
			printf("%s%d",i-1?" ":"",s);
		}
		puts("");
	}
	return 0;
}