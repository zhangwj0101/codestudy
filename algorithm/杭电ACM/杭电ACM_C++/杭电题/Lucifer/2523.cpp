////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-31 20:50:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2523
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int N[2001];
char K[4001];
int main()
{
	int n,t,k,i,j,max,c;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&N[i]);
		sort(N,N+n-1);
		max=0;
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				c=(N[i]-N[j]);
				if(c<0)c=-c;
				if(max<c)max=c;
				K[c]=1;
			}
		for(n=0,i=0;i<=2000;i++)
			if(K[i])
			{
				if(++n==k)
				{
				printf("%d\n",i);
				break;
				}
				K[i]=0;
			}
		memset(K+i,0,max+1-i);
	}
	return 0;
}