////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-12 17:54:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1859
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,m,i,mx1,my1,mx2,my2;
	while(true)
	{
		mx1=my1=232;
		mx2=my2=-232;
		for(i=0;cin>>n>>m;i++)
		{
			if(n||m)
			{
				if(mx1>n)
					mx1=n;
				if(mx2<n)
					mx2=n;
				if(my1>m)
					my1=m;
				if(my2<m)
					my2=m;
			}
			else
				break;
		}
		if(i)
			cout<<mx1<<" "<<my1<<" "<<mx2<<" "<<my2<<endl;
		else
			break;
	}
	return 0;
}