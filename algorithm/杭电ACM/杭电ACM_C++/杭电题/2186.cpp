////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-26 09:50:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2186
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int c,n,n1,n2,n3,s;
	cin>>c;
	while(c--)
	{
		cin>>n;
		n1=n/2;
		n2=(n-n1)*2/3;
		n3=n-n1-n2;
		s=(n1+9)/10+(n2+9)/10+(n3+9)/10;
		cout<<s<<endl;
	}
    return 0;
}