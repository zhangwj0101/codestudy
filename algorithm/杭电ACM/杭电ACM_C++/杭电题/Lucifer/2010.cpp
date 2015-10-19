////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 22:53:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2010
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
bool f(int i)
{
	int s;
	s=(i/100)*(i/100)*(i/100)+(i%10)*(i%10)*(i%10)+(i/10%10)*(i/10%10)*(i/10%10);
	if(s==i)
		return true;
	else
		return false;
}

int main()
{
	int flag;
   int m,n,i,s[900];
   while(cin>>m>>n)
   {
	   flag=0;
	   for(i=m;i<=n;i++)
		{
			if(f(i))
			{
				s[flag++]=i;
			}
		}
	   if(!flag)
		   cout<<"no";
	   else
			for(i=0;i<flag;i++)
			{
				cout<<s[i];
				if(i<flag-1)
					cout<<" ";
			}
		cout<<endl;
   }      
   return 0;
}

