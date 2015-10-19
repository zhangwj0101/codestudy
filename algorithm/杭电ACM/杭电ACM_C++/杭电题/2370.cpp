////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-08-30 20:32:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2370
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int F[21]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711};
int main()
{
	int i,a,b,c;
	int t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>x;
		for(y=0,i=19;i>0;i--)
		{
			if(F[i]<=x)
			{
				x-=F[i];
				y+=F[i-1];
			}
		}
		cout<<y<<endl;
	}
   return 0;
}