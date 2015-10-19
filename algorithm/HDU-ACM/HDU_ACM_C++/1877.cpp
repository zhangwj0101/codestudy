////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-08 21:28:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1877
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
    int digit[40],m,n,i;
    long a,b;
    cin>>m;
    while(m!=0)
    {
        n=0;
        cin>>a>>b;
        a=a+b;
		if(a==0)
			cout<<0;
		else
		{
			while(a>0)
			{
	           digit[n++]=a%m;
				a/=m;
			}
			for(i=n-1;i>=0;i--)
				cout<<digit[i];
		}
        cout<<endl;
        cin>>m;
    }
   return 0;
}