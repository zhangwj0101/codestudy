////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-12-10 16:41:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2560
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,s,n,m,a,i;
	cin>>t;
	while(t--)
	{
		s=0;
		scanf("%d%d",&n,&m);
		n*=m;
		for(i=0;i<n;i++)
			scanf("%d",&a),s+=a;
		printf("%d\n",s);
	}
	return 0;
}