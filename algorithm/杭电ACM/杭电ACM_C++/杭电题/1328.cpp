////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-08 23:18:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1328
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,sl,i,j;
	char c[80];
	while(cin>>n)
	{
		for(j=0;j<n;j++)
		{
			cin>>c;
			sl=strlen(c);
			for(i=0;i<sl;i++)
			{
				c[i]=(c[i]-'A'+1)%26+'A';
			}
			printf("String #%d\n%s\n\n",j+1,c);
		}
	}
	return 0;
}