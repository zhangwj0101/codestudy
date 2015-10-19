////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-26 21:26:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

int main()
{
	int i,j,n,s[100],sb[100],t;
   cin>>n;
   while(n!=0)
   {
	   for(i=0;i<n;i++)
	   {
		   cin>>s[i];
		   sb[i]=s[i];
		   if(sb[i]<0)
			   sb[i]*=-1;
	   }

		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
				if(sb[i]<sb[j])
				{
					t=sb[i];
					sb[i]=sb[j];
					sb[j]=t;
					t=s[i];
					s[i]=s[j];
					s[j]=t;
				}
		}
		for(i=0;i<n;i++)
		{
			cout<<s[i];
			if(i<n-1)
				cout<<" ";
		}
		cout<<endl;
	   cin>>n;
   }
      
   return 0;
}

