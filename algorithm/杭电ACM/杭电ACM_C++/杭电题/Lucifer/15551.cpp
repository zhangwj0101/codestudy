////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-24 23:00:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1555
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int k;
int day(int m)
{
	if(m/k>0)
		return m/k*k+day(m%k+m/k);
	else
		return m;
}
int main()
{
	int m;
	while(cin>>m>>k&&m)
			cout<<day(m)<<endl;
    return 0;
}