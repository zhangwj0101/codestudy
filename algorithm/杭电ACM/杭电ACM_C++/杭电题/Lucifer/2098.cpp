////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-03 08:43:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2098
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define M	10001
bool notPrime[M]={1,1,0,0,1,0};
void creat_prime()
{
	int i,j;
	for(i=2;i<=M;i++)
		if(!notPrime[i])
			for(j=i+i;j<=M;j+=i)
				notPrime[j]=1;
} 
int main()
{
	int n,k,i;
	creat_prime();
	while(cin>>n&&n)
	{
		for(k=0,i=1;i<n/2;i+=2)
			if(!notPrime[i]&&!notPrime[n-i])
				k++;
		cout<<k<<endl;
	}
   return 0;
}