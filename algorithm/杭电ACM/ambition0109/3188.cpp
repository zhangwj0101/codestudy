////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-26 13:45:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3188
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

void main()
{
	int n,a,b,c;
	for(scanf("%d",&n);n;n--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a)
			printf("good\n");
		else if(a==b||b==c||a==c)
			printf("perfect\n");
		else
			printf("just a triangle\n");
	}
}