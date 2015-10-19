////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-17 22:56:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1056
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int i;
	double c,s;
	while(cin>>c&&c)
	{
		s=0;
		for(i=2;s<c;i++)
			s+=1.0/i;
		cout<<i-2<<" card(s)"<<endl;
	}
	return 0;
}