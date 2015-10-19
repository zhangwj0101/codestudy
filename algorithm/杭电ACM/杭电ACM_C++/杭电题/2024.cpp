////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-11 16:59:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2024
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstring>
using namespace std;                      //标识符由字母、下划线、数字这三个方面组成，但开头必须是字母或下划线,关键字不能是标识符，如main等。
bool d(char c)
{
	if(isalpha(c)||isdigit(c)||(c=='_'))
		return true;
	else
		return false;
}
bool f(char c[])
{
	int sl,i;
	sl=strlen(c);
	if(c[0]=='_'||isalpha(c[0]))
	{
		for(i=1;i<sl;i++)
		{
			if(!d(c[i]))
				return false;
		}
		return true;
	}
	else
		return false;
	
}
int main()
{
	int n;
	char s[80];
	cin>>n;
	getchar();
	while(n--)
	{
		cin.getline(s,80);   //cin>>s;
		if(f(s))
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}