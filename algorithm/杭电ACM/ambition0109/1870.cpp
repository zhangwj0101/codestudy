////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 09:26:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1870
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

void main()
{
	string str;
	while(cin>>str)
	{
		int n=0;
		for(unsigned i=0;i<str.length();i++)
		{
			if(str[i]=='(') n++;
			else if(str[i]==')') n--;
			else if(str[i]=='B'){
				cout<<n<<endl;
				break;
			}
		}
	}
}