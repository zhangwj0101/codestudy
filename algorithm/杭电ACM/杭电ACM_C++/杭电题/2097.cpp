////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-26 11:07:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2097
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const int d[3]={10,16,12};
int main()
{
	int i,n,n1,s[3];
	while(cin>>n&&n)
	{
		for(n1=n,i=0;i<3;i++)
		{
			s[i]=0;
			n=n1;
			while(n)
			{
				s[i]+=n%d[i];
				n/=d[i];
			}
		}
		cout<<n1<<" is ";
		if((s[0]!=s[1])||(s[1]!=s[2]))
			cout<<"not ";
		cout<<"a Sky Number.\n";
	}
    return 0;
}