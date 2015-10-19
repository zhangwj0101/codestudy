////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-01 23:18:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1164
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
const int M=65536;
int p[10000]={2};
int main()
{
	int i,j,n,t,a[257];
	for(i=3,n=1;i<M;i+=2)
    {
        for(j=2;j<=sqrt(1.0*i);j++)
            if(i%j==0)
                break;
        if(j>sqrt(1.0*i))
            p[n++]=i;
    }
	while(cin>>n)
	{
		for(t=n,i=0,j=0;i<10000&&(t!=1);i++)
		{
			for(;t%p[i]==0;t/=p[i])
				a[j++]=p[i];
		}
		for(i=0;i<j;i++)
			cout<<(i?"*":"")<<a[i];
		cout<<endl;
	}
   return 0;
}