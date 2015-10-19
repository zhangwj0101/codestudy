////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-06 00:15:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1212
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int b,i,sl,temp;
	char a[1001];
	while(cin>>a>>b)
	{
		sl=strlen(a);
		for(temp=i=0;i<sl;i++)
			temp=temp*10%b+(a[i]-'0')%b;
		cout<<temp%b<<endl;
	}
	return 0;
}