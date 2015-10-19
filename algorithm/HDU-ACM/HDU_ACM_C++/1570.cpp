////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-10 23:17:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int p[11]={1},i,s,t,m,n;
	char ch;
	for(i=1;i<11;i++)
		p[i]=p[i-1]*i;
	cin>>t;
	while(t--)
	{
		cin>>ch>>n>>m;
		s=p[n]/p[n-m];
		if(ch=='C')
			s/=p[m];
		cout<<s<<endl;
	}
    return 0;
}