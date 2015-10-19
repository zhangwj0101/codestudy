////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 21:45:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2075
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int i,n,a,b;
	cin>>n;
   for(i=0;i<n;i++)
   {
	   cin>>a>>b;
	   if(a%b==0)
		   cout<<"YES"<<endl;
	   else
		   cout<<"NO"<<endl;
   }
   return 0;
}