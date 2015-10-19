////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-02 12:12:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2052
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int i,j,n,m;
	char a[80][80]={0};
	while( cin>>n>>m)
	{
		a[0][0]=a[0][n+1]=a[m+1][0]=a[m+1][n+1]='+';
		for(i=1;i<=n;i++)
			a[m+1][i]=a[0][i]='-';
		for(j=1;j<=m;j++)
			a[j][0]=a[j][n+1]='|';
		
		for(i=0;i<m+2;i++)
		{
			for(j=0;j<n+2;j++)
			{
				if(a[i][j])
				{
					 cout<<a[i][j];
					a[i][j]=0;
				}
				else
					 cout<<" ";
			}
			 cout<<"\n";
		}
		cout<<"\n";
	}
   return 0;
}