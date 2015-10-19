////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-31 21:13:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2521
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int c[5001]={0},t,i,j,a,b,max;
	for(i=1;i<=5000;i++)
		for(j=i;j<=5000;j+=i)
			c[j]++;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&a,&b);
		for(max=i=a;i<=b;i++)
			if(c[max]<c[i])
				max=i;
		printf("%d\n",max);
	}
	return 0;
}