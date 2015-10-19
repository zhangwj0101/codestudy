////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-01 15:20:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2124
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[600],l,n,i;
	while(scanf("%d%d",&l,&n)==2)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		for(--i;i>=0;i--)
		{
			l-=a[i];
			if(l<=0)break;
		}
		if(l>0)puts("impossible");
		else printf("%d\n",n-i);
	}
	return 0;
}