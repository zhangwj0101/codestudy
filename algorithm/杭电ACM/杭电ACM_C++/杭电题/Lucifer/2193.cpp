////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-29 20:48:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2193
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int h[50]={1,2};
	int n,i;
	for(i=2;i<43;i++)
		h[i]=h[i-1]+h[i-2]+1;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<43;i++)
			if(n<h[i])
				break;
		printf("%d\n",i-1);
	}
	return 0;
}