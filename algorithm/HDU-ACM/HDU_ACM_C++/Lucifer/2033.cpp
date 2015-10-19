////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-27 12:49:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,i,j,a[3],b[3],c[3],carry;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
			cin>>a[j];
		for(j=0;j<3;j++)
		{
			cin>>b[j];
			c[j]=0;
		}

		for(j=2;j>0;j--)
		{
			c[j]+=(a[j]+b[j]);
			carry=0;
			if(c[j]>=60)
			{
				carry=c[j]/60;
				c[j]%=60;
			}
			if(carry)
				c[j-1]+=carry;
		}
		c[0]+=(a[0]+b[0]);
		for(j=0;j<3;j++)
		{
			cout<<c[j];
			if(j<2)
				cout<<" ";
		}
			cout<<endl;

	}
   return 0;
}