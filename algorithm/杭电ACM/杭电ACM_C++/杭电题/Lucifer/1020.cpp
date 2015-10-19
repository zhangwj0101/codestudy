////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-10 23:29:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,i,j,k,l;
	char s[10000],t;
	cin>>n;
	for(i=0;i<n;i++)
   {
	   cin>>s;
	   l=strlen(s);
	   for(j=0;j<l;)
	   {
		   for(t=s[j],k=0;(t==s[j])&&j<l;j++,k++);
			if(k==1)
				cout<<t;
			else
				cout<<k<<t;
	   }
	   cout<<endl;
   }
   return 0;
}