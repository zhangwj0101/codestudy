////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-02 12:33:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2055
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	char c;
	int i,n,t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>c>>n;
		if(isupper(c))
			c-=64;
		else
			c=-1*c+96;
		cout<<c+n<<endl;
	}
   return 0;
}