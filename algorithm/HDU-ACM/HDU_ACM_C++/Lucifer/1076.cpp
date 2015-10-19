////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 20:37:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1076
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

bool leap(int Y)
{
	if (((Y%4==0)&&(Y%100!=0))||(Y%400==0))
		return true;
	else
		return false;

}

int main()
{
	int i,k,n,s,t;
	cin>>n;
   for(i=0;i<n;i++)
   {
		cin>>s>>t;
		
		while(!leap(s))
			s++;
		k=0;
		do
		{
			if(leap(s))
				k++;
			s+=4;
		}while(k<t);
		s-=4;
		cout<<s<<endl;

		
   }
  
   return 0;
}

