////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 23:13:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

int f(int n)
{
	return n*n+n+41;
}

bool prime(int n)
{
	int i;
	for(i=2;i<n/2;i++)
		if(n%i==0)
			return false;
	if(i>=n/2)
		return true;
}

int main()
{
	int a,b,flag,i;
	cin>>a>>b;
   while(a!=0||b!=0)
   {
	   flag=1;
	   for(i=a;i<=b;i++)
		{
		   if(!prime(f(i)))
			   flag=0;
		}
	   if(flag)
		   cout<<"OK"<<endl;
	   else
		   cout<<"Sorry"<<endl;
	   cin>>a>>b;
   }      
   return 0;
}

