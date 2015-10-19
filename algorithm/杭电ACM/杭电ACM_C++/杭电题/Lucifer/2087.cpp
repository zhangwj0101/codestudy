////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 22:36:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2087
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	char s[1001],sub[1001],*p;
	int c,sl;
	while(cin>>s&&(*s!='#'))
	{
		cin>>sub;
		sl=strlen(sub);
		for(p=s,c=0;p=strstr(p,sub);c++,p+=sl);
		cout<<c<<endl;
	}
   return 0;
}