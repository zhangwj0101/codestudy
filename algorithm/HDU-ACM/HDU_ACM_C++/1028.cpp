////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-19 19:16:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1028
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int lmax=10000;    
int c1[lmax+1],c2[lmax+1];
int main()
{	
	int n,i,j,k;
	while (cin>>n)
	{
		memset(c2,0,4*n+4);
		 for (i=0;i<=n;i++)
			 c1[i]=1;
		 for (i=2;i<=n;i++)
		 {	
			 for (j=0;j<=n;j++)
				for (k=0;k+j<=n;k+=i)
				{
					c2[j+k]+=c1[j];
				}
			for (j=0;j<=n;j++)
			{
				c1[j]=c2[j];	
				c2[j]=0;
			}
		 }
		 cout<<c1[n]<<endl;
	}
	return 0;
}
