////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-08 21:07:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2140
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const char trans[26]={'c',' ','a','d','i','f','g','h','e','j','k','m','l','n','o','p',',','r','s','!','u','v','w','x','y','z'};
int main()
{
	int i,sl;
    char c[10000];
	while(scanf("%s",c)==1)
	{
		sl=strlen(c);
		for(i=0;i<sl;i++)
		{
			c[i]=trans[c[i]-'a'];
		}
		puts(c);
	}
    return 0;
}