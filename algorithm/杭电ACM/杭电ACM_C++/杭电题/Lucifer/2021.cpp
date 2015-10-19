////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-05 16:57:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2021
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const int a[6]={100,50,10,5,2,1};
int main()
{
	int i,j,n,s,t;
	while(cin>>n)
	{
		if(!n)
			break;
		for(s=0,i=0;i<n;i++)
		{
			cin>>t;
			for(j=0;t;j++)
			{
				s+=t/a[j];
				t%=a[j];
			}
		}
		cout<<s<<endl;
	}
   return 0;
}