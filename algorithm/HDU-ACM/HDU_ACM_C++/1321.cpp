////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-08 23:10:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1321
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,sl,i;
	char c[80],c1[80];
	while(cin>>n)
	{
		getchar();
		while(n--)
		{
			gets(c);
			sl=strlen(c);
			for(i=sl-1;i>=0;i--)
				c1[i]=c[sl-i-1];
			c1[sl]=0;
			puts(c1);
		}
	}
	return 0;
}