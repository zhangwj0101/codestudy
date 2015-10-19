////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 22:30:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2008
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{

   int n,i,s1,s2,s3;
   float t;
   cin>>n;
   while(n!=0)
   {
	   s1=s2=s3=0;
	   for(i=0;i<n;i++)
	   {
		   cin>>t;
		   if(t>0)
			   s1++;
		   else if(t<0)
			   s2++;
		   else
			   s3++;
	   }
	   cout<<s2<<" "<<s3<<" "<<s1<<endl;
	   cin>>n;
   }
   return 0;
}
