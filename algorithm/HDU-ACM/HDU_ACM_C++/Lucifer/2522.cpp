////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-30 23:57:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2522
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int M=1000001;
char remainder[M],quotient[M];
void main()
{
	int t,n,m,max;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		if(n<0){n=-n;printf("-");}
		max=m=1;
		if(n==1)
		{
			puts("1");
			continue;
		}
		for(int i=1;i<=100000;i++)
		{
			remainder[m]=i;
			m*=10;
			quotient[i]=m/n+'0';
			m%=n;
			if(m==0||remainder[m]!=0)
			{
				cout<<"0.";
				quotient[i+1]=0;
				puts(quotient+1);
				memset(remainder,0,max*4);
				break;
			}
			if(max<m)max=m;
		}
	}
}