////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-26 00:13:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2016
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,s[100],i,t,k;
	cin>>n;
	while(n!=0)
   {
	   t=0;
	   for(i=0;i<n;i++)
		  cin>>s[i];
	   k=0;
		for(i=1;i<n;i++)
				if(s[k]>s[i])
					k=i;
		t=s[k];
		s[k]=s[0];
		s[0]=t;
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

