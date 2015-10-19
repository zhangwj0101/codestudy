////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-25 11:45:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:734MS
////Run memory:124KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int t,i,a[50001],ti,tj,n,j,k,sum;
	char c[6];
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case "<<i<<":\n";
		cin>>n;
		for(j=1;j<=n;j++)
			cin>>a[j];
		while(cin>>c)
		{
			if(*c=='E')
				break;
			cin>>ti>>tj;
			switch(*c)
			{
			case 'Q':
				for(k=ti,sum=0;k<=tj;k++)
					sum+=a[k];
				cout<<sum<<endl;
				break;
			case 'A':
				a[ti]+=tj;
				break;
			case 'S':
				a[ti]-=tj;
				break;
			}
		}
	}
    return 0;
}

