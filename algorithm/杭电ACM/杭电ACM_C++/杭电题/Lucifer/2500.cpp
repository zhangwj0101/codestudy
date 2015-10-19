////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-13 12:10:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2500
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
char str[]="HDU";
int main()
{
	int n,m,i,j;
	cin>>n;
	while(n--)
	{
		scanf("%d",&m);
		for(i=0;i<3*m;i++)
		{
			for(j=0;j<m;j++)
				printf("%s",str);
			puts("");
		}
	}
   return 0;
}