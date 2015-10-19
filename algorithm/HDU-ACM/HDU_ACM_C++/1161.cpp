////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-02 21:52:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1161
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cctype>
using namespace std;
int main()
{
	char s[1000];
	int k;
	while(cin.getline(s,1000))
	{
		k=-1;
		while(s[++k])
			if(isupper(s[k]))
				s[k]+=32;
		cout<<s<<endl;
	}
   return 0;
}