////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-04 22:20:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:796MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t,n,s,tt,i;
	cin>>t;
	while(t--)
	{
		s=1;
		scanf("%d",&n);
		tt=(int)sqrt(1.0*n);
		for(i=2;i<=tt;i++)
		{
			if(n%i==0)
				s+=i+n/i;
		}
		if((i-1)*(i-1)==n)
			s-=i-1;
		printf("%d\n",s);
	}
   return 0;
}