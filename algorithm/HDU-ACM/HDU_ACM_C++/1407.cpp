////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 20:14:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1407
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,j,k,n,t,s1,s2,f;
	while(cin>>n)
	{
		t=sqrt(1.0*n);
		for(f=1,i=1;i<=t;i++)
			for(s1=i*i,j=1;(j<=t)&&(j*j+s1<n);j++)
				for(s2=s1+j*j,k=1;(k<=t)&&(s2+k*k<=n);k++)
					if(s2+k*k==n)
					{
						goto l;
						break;
					}
		l:
		cout<<i<<" "<<j<<" "<<k<<endl;
	}
    return 0;
}