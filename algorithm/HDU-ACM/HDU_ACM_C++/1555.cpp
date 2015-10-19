////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 22:33:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1555
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int i,m,k;
	cin>>m>>k;
   while(m!=0||k!=0)
   {
	   for(i=1;i<m;)
		   if(++i%k==0)
			   m++;
	   cout<<i<<endl;
	   cin>>m>>k;
   }
   return 0;
}