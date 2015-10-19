////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-13 18:49:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2203
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:8KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
char s1[200001],s2[100001];
int main()
{
	int sl;
	while(scanf("%s%s",s1,s2)==2)
	{
		sl=strlen(s1);
		memcpy(s1+sl,s1,sl+1);
		puts(strstr(s1,s2)?"yes":"no");
	}
   return 0;
}