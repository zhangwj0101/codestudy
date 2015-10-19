////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-08-30 18:58:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2368
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
#define INF 1e-8
using namespace std;
int main()
{
	int i;
	double r,w,l,pr;
   for(i=1;cin>>r&&r;i++)
   {
		cin>>w>>l;
		pr=sqrt(w*w+l*l);
		cout<<"Pizza "<<i<<((pr-2*r>INF)?" does not fit":" fits")<<" on the table.\n";
   }
   return 0;
}