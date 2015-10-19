////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-31 01:21:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2519
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	__int64 a[16]={1,1},c[31][31]={0},m=1;
	int i,j,n;
	for(i=1;i<=30;i++)
	{
		c[i][0]=1,c[i][1]=i;
		for(m=i,j=2;j<=i/2;j++)
		{
			m=m*(i-j+1)/j;
			c[i][j]=m;
		}
	}
	cin>>i;
	while(i--)
	{
		scanf("%d%d",&n,&m);
		if(n>=m)
		{
			if(2*m>n)m=n-m;
			printf("%I64d\n",c[n][m]);
		}
		else
			puts("0");
	}
	return 0;
}