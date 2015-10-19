////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 21:27:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2060
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,bl,ps,os;
	cin>>n;
	while(n--&&cin>>bl>>ps>>os)//莫非这里错了
	{
		ps+=bl>6?8*(bl-6):0;
		ps+=bl>6?27:bl*(15-bl)/2;
		puts(ps>=os?"Yes":"No");
	}
   return 0;
}