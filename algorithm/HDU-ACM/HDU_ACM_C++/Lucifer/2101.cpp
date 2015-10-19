////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 13:40:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2101
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	long n,m;
	while(cin>>m>>n)
	{
		if((m+n)%86)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
   return 0;
}
