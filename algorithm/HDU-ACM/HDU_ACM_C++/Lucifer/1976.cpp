////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-20 21:19:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1976
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,i,j,a[2][3];
	scanf("%d",&t);
	while(t--)
	{
		for(j=0;j<2;j++)
		for(i=0;i<3;i++)
		{
			scanf("%d",&a[j][i]);
		}
		for(i=0;i<3;i++)
		{
			if(a[0][i]>a[1][i])
			{
				puts("First");
				break;
			}
			else if(a[0][i]<a[1][i])
			{
				puts("Second");
				break;
			}
		}
		if(i==3)puts("Same");
	}
	return 0;
}