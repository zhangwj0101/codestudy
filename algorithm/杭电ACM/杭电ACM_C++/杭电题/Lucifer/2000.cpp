////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 21:18:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2000
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	char a[3],t;
	int i,j;
	while(cin>>a[0]>>a[1]>>a[2])
	{
		for(i=0;i<2;i++)
			for(j=i+1;j<3;j++)
				if(a[i]>a[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
		for(i=0;i<3;i++)
		{
			cout<<a[i];
			if(i<2)
				cout<<" ";
		}
		cout<<"\n";
	}
	

	return 0;
}