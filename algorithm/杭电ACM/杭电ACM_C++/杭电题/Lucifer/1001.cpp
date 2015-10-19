////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-24 23:23:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
   int a,s,i;
   while(cin >> a)
   {
	   s=0;
		for(i=1;i<=a;i++)
		{
			s+=i;	
		}
		cout << s<<"\n"<<endl;
   }
      
   return 0;
}

