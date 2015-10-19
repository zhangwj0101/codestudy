////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-08 20:44:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int fun(int n)
{
    
    if(n==0)
        return 1;
    else
    {
        int s=1;
        for(int i=1;i<=n;i++)
        {
            s*=i;
        }
        return s;
    }
    
}

int main()
{

   double e=0;
   cout<<"n e"<<endl;
   printf("- -----------\n");
   for(int i=0;i<=9;i++)
   {
       e=e+1.0/fun(i);
	   if(i<=2)
		   cout<<i<<" "<<e<<endl;
	   else
			printf("%d %.9f\n",i,e);
   }
   return 0;
}