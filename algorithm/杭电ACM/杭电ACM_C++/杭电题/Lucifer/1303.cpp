////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-08 21:36:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1303
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int a[16],t,i,c,n,j;
	while(cin>>t&&t>=0)
	{
		n=0;
		memset(a,0,sizeof(a));
		a[n++]=t;
		while(cin>>t&&t)
			a[n++]=t;
		for(c=0,i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(2*a[i]==a[j])
					c++;
		cout<<c<<endl;
	}
	return 0;
}