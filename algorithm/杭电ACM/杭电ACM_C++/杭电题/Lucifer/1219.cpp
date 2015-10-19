////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-06 06:53:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1219
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int i,sl;
	char a[100001];
	int s[26];
	while(gets(a))
	{
		memset(s,0,sizeof(s));
		sl=strlen(a);
		for(i=0;i<sl;i++)
			if(islower(a[i]))
				s[a[i]-'a']++;
		for(i=0;i<26;i++)
			printf("%c:%d\n",'a'+i,s[i]);
		puts("");
	}
	return 0;
}