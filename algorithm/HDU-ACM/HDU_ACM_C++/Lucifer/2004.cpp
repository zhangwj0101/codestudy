////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 21:57:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	const char s[11]={'E','E','E','E','E','E','D','C','B','A','A'}; 
   int a;
   while(cin>>a)
   {
	   if(a<0||a>100)
		   cout<<"Score is error!"<<endl;
	   else
		   cout<<s[a/10]<<endl;
   }
   return 0;
}
