////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-21 20:12:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1880
////Problem Title: 
////Run result: Accept
////Run time:750MS
////Run memory:21552KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> dicMap;
map<string, string> dicMap2;

int main()
{
	char t[120];
	while (gets(t))
	{
		if (!strcmp(t, "@END@")) break;
		string ss = t;
		int i = ss.find(']');
		string a = ss.substr(0, i + 1);
		string b = ss.substr(i + 2, ss.length() - i);
		dicMap[a] = b;
		dicMap2[b] = a;
	}
	int n;
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		gets(t);
		if (t[0] == '[')
		{
			string ans = dicMap[t];
			if (ans == "") printf("what?\n");
			else printf("%s\n", ans.c_str());
		}
		else
		{
			string ans = dicMap2[t];
			if (ans == "") printf("what?\n");
			else printf("%s\n", ans.substr(1, ans.length() - 2).c_str());
		}
	}
	return 0;
}
