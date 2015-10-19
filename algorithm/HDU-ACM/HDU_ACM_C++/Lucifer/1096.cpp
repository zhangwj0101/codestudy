////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-27 10:05:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
   int a,i,j,t,n,s;
   cin>>n;
   for(j=0;j<n;j++)
   {
        cin>>t;
       s=0;
        for(i=0;i<t;i++)
        {
            cin>>a;
            s+=a;
        }
        cout<<s<<endl;
		if(j<n-1)
			cout<<endl;
   }
   return 0;
}
