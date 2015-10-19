////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-05 17:12:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2029
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int i,j,l,n,f;
	char s[100];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		l=strlen(s);
		for(j=0,f=1;j<l/2;j++)
		{
			if(s[j]!=s[l-j-1])
			{
				f=0;
				break;
			}
		}
		if(f)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
   return 0;
}