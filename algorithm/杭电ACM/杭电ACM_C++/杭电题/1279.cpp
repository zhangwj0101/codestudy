////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-05 23:19:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1279
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int M=1000;
int main()
{
	int f,c,n,i;
	while(cin>>c)
	{
		while(c--)
		{
			cin>>n;
			f=i=0;
			while(n%2==0)n/=2;
			if(n!=1)
			{
				do
				{
					if(n==5)
					{
						f++;
						cout<<(i++?" ":"")<<n;
						break;
					}
					if(n%2)
					{
						cout<<(i++?" ":"")<<n;
						f++;
						n=n*3+1;
					}
					else
						n/=2;
				}while(n!=1);
				cout<<endl;
			}
			if(!f)
				cout<<"No number can be output !\n";
		}
	}
	return 0;
}