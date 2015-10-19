////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-26 10:19:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2188
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int c,n,m;
	cin>>c;
	while(c--)
	{
		cin>>n>>m;
		if(n%(m+1))
			cout<<"Grass\n";
		else
			cout<<"Rabbit\n";
	}
    return 0;
}