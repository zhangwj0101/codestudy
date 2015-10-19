////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 21:12:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int i,k,t,n,s[1000];
	cin>>n;
   while(n!=0)
   {
	   for(i=0;i<n;i++)
		   cin>>s[i];
	   cin>>t;
		for(k=0,i=0;i<n;i++)
			if(t==s[i])
				k++;
		cout<<k<<endl;
		cin>>n;
   }
   return 0;
}