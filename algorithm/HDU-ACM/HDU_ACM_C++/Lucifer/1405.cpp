////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 20:49:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1405
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
using namespace std;
const int M=65536;
int p[10000]={2};
int main()
{
	int i,n,j,k,c;
	for(i=3,n=1;i<M;i+=2)
	{
		for(j=2;j<=sqrt(1.0*i);j++)
			if(i%j==0)
				break;
		if(j>sqrt(1.0*i))
			p[n++]=i;
	}
	for(i=1;cin>>n&&n>0;i++)
	{
		cout<<((i-1)?"\n":"")<<"Case "<<i<<".\n";
		for(k=0,j=0;n>1;j++)
		{
			c=0;
			while(n%p[j]==0)
			{
				n/=p[j];
				c++;
			}
			if(c>0)
				cout<<p[j]<<" "<<c<<" ";
		}
		cout<<endl;
	}
   return 0;
}