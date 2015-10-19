////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 10:42:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1999
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2204KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int num[500001];
bool sum[1001];
void main()
{
	memset(sum,false,sizeof(sum));
	for(int i=1;i<500001;i++)
	{
		if(num[i]<1001)
			sum[num[i]]=true;
		for(int j=i+i;j<500001;j+=i)
			num[j]+=i;
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(sum[n])
			cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
}