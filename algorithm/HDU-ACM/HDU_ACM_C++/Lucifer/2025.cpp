////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-05 17:06:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2025
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int i,t,l,m;
	char s[100];
	while(cin>>s)
	{
		l=strlen(s);
		for(i=1,m=0;i<l;i++)
			if(s[m]<s[i])
				m=i;
		t=s[m];
		for(i=0;i<l;i++)
		{
			cout<<s[i];
			if(s[i]==t)
				cout<<"(max)";
		}
		cout<<endl;
	}
   return 0;
}