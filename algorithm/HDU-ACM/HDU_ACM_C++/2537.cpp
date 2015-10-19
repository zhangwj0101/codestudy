////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-01-08 20:13:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2537
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,m,i,f;
	char s[20];
	while (scanf("%d",&n),n)
	{
		scanf("%s",s);
		for(m=i=0;i<n;i++)
			if(s[i]=='R')m++;
		f=0;
		if (m==7&&(n-m<=7||s[n-1]=='B')) f=1;
		else if(n-m<=7&&s[n-1]=='L') f=1;
		puts(f?"Red":"Yellow");
	}
	return 0;
}