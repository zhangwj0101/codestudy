////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 23:14:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2154
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int p[1001]={0,0,2,2};
int main()
{
	int k,i,n;
	for(k=2,i=4;i<1001;i++)
	{
		k<<=1;
		k%=10000;
		p[i]=(p[i-2]+k)%10000;
	}
	while(scanf("%d",&n),n)
		printf("%d\n",p[n]);
   return 0;
}