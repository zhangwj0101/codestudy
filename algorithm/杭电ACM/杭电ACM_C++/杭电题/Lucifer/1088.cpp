////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-26 00:31:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
#define NL puts(""),i=0
char h[]="--------------------------------------------------------------------------------";
int main()
{
	char a[82];
	int i=0,s;
	while(cin>>a)
	{
		s=strlen(a);
		if(a[0]!='<')
		{
			if(i+s+1<=80)
			{
				if(i)
					printf(" "),i++;
			}
			else
				NL;
			printf("%s",a);
			i+=s;
		}
		else
		{
			if(a[1]=='b')
				NL;
			else
			{
				if(i)
					puts("");
				i=0,puts(h);
			}
		}
	}
	puts("");
    return 0;
}