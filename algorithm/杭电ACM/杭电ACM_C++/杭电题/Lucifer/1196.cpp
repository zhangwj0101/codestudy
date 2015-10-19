////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-11 00:51:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1196
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,a,i;
	cin>>n;
	while(n!=0)
	{
		for(a=1,i=1;!(n-(n>>i<<i));i++);
		cout<<(a<<i-1)<<endl;
		cin>>n;
	}
   return 0;
}