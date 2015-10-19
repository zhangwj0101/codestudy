////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-21 15:42:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2083
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int num[501];
void main()
{
	int t,n,m,sum;
	for(cin>>t;t>0;t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>num[i];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(num[i]>num[j])
				{num[i]^=num[j];num[j]^=num[i];num[i]^=num[j];}
		sum=0;
		for(int i=0;i<n/2;i++)
			sum+=num[n-i-1]-num[i];
		cout<<sum<<endl;
	}
}