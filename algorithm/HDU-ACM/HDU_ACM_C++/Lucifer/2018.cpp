////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-26 21:00:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2018
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	long t;
	int n,i,j,a[4]={1,1,1,1},m;
   cin>>n;
   while(n!=0)
   {
	   t=0;
	   if(n>4)
	   {
		   for(i=0;i<4;i++)
				a[i]=1;
		   for(i=0;i<n-4;i++)
			{
				t+=a[0];
				m=a[3];
				for(j=0;j<3;j++)
					a[j]=a[j+1];
				a[3]=m+a[0];
			}
			for(j=0;j<4;j++)
					t+=a[j];
	   }
	    else
			for(j=0;j<n;j++)
					t+=a[j];
		cout<<t<<endl;
	   cin>>n;
   }
      
   return 0;
}

