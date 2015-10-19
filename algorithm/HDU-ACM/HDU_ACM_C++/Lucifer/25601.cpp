////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-12-10 16:55:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2560
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	char buf[100][210];
	int t,s,n,m,i,j;
	cin>>t;
	while(t--)
	{
		s=0;
		scanf("%d%d",&n,&m);
		getchar();
		for(i=0;i<n;i++)
			gets(buf[i]);
		for(i=0;i<n;i++)
			for(j=0;j<2*m;j+=2)
				s+=(buf[i][j]^'0');
		printf("%d\n",s);
	}
	return 0;
}