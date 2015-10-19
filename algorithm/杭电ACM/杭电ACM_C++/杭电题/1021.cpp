////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-18 00:47:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	long n;
	while(cin>>n)
		if(((n+2)%8==0)||((n+6)%8)==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
    return 0;
}