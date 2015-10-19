////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 14:49:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1898
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,a,b,t;
	cin>>n;
	while(n--)
	{
		scanf("%d%d%d",&a,&b,&t);
		if(t%a==t%b)
			puts("Both!");
		else
			puts(t%b>t%a?"Sempr!":"Xiangsanzi!");
	}
   return 0;
}