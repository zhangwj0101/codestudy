////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-11 23:58:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1870
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	char b[1000];
	int sl,i,c;
	while(cin>>b)
	{
		sl=strlen(b);
		for(c=i=0;i<sl;i++)
		{
			if(b[i]=='(')
				c++;
			else if(b[i]==')')
				c--;
			else
				break;
		}
		cout<<c<<endl;
	}
	return 0;
}