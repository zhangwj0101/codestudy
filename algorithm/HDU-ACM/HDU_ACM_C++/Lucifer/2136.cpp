////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-27 17:31:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2136
////Problem Title: 
////Run result: Accept
////Run time:984MS
////Run memory:3820KB
//////////////////System Comment End//////////////////
//∏ﬂ ÷
#include<iostream>
using namespace std;
const int MAX_NUM=1000000;
int prime[MAX_NUM];
int num;
int main()
{
	int i,j,n;
	memset(prime, 0, sizeof(prime));
	for(i = 2; i<MAX_NUM; i++)
	{        
		if(!prime[i])
		{
			num++;
			for(j = i; j <MAX_NUM; j+=i)
				prime[j] = num;
		}
	}
	while(cin>>n)
		printf("%d\n",prime[n]);
    return 0;
}