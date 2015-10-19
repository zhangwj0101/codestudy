////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-01-08 17:26:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2564
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,sl,i;
	char s[200];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(s);
		for(i=0;s[i]==' ';i++);
		putchar(toupper(s[i]));
		sl=strlen(s);
		for(;i<sl;i++)
		{
			if((s[i+1]==' ')&&isalpha(s[i+2]))
			{
				putchar(toupper(s[i+2]));
			}
		}
		puts("");
	}
	return 0;
}