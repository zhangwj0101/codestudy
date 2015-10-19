////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-16 07:43:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1194
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,a,b,s,d;
	cin>>n;
	while(n--)
	{
		cin>>s>>d;
		a=s+d;
		b=s-d;
		a=a%2?-1:a/2;
		b=b%2?-1:b/2;
		if((b<0)||(a<0))
			puts("impossible");
		else
			printf("%d %d\n",a,b);
	}
    return 0;
}