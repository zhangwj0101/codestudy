////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-20 21:07:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1000
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

void main() 
{
	int a,b;
	while(1)
	{
		cin>>a>>b;
		try{
			if(!cin)
				throw invalid_argument("");
			cout <<a+b<< endl;
		}
		catch(invalid_argument err){
			break;
		}
	}
} 