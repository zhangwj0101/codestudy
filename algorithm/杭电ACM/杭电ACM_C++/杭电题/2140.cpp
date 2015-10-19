////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-16 21:14:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2140
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const char trans[26]={'c',' ','a','d','i','f','g','h','e','j','k','m','l','n','o','p',',','r','s','!','u','v','w','x','y','z'};
int main()
{
	char c;
	while(scanf("%c",&c)==1)putchar(c!='\n'?trans[c-'a']:c);
	return 0;
}