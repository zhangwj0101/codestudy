////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-13 19:51:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2086
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,i;
	double a0,an1,c,cs;
	while(cin>>t)
	{
		cin>>a0>>an1;
		for(cs=0,i=1;i<=t;i++)
		{
			cin>>c;
			cs+=2*(t-i+1)*c;
		}
		printf("%.2lf\n",(t*a0+an1-cs)/(t+1));
	}
   return 0;
}