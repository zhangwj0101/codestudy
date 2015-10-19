////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-02 15:36:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2091
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	char c;
    int i,j,n,f=1;
    while(cin>>c)
    {
		if(c=='@')
			break;
		cin>>n;
		if(!f)
			cout<<endl;
		else
			f=0;
		for(i=0;i<n-1;i++)
		{
			for(j=1;j<n-i;j++)
				cout<<' ';
			if(i!=0)
				cout<<c;
			for(j=2*i-1;j>0;j--)
				cout<<' ';
			cout<<c<<endl;
		}
		for(i=0;i<2*n-1;i++)
			cout<<c;
		cout<<endl;
    }
   return 0;
}