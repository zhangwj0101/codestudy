////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-29 13:22:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2159
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int evil[101][2];
int bag[101][101];
void main()
{
	int n,m,k,s,t;
	while(cin>>n>>m>>k>>s)
	{
		for(int i=0;i<=s;i++)
			for(int j=0;j<=m;j++)
				bag[i][j]=0;
		for(int i=0;i<k;i++)
			cin>>evil[i][0]>>evil[i][1];
		t=m+1;
		for(int i=1;i<=s;i++)
		{
			for(int j=0;j<k;j++)
			{
				for(int l=evil[j][1];l<=m;l++)
				{
					if(evil[j][0]+bag[i-1][l-evil[j][1]]>bag[i][l])
						bag[i][l]=evil[j][0]+bag[i-1][l-evil[j][1]];
					if(bag[i][l]>=n&&l<t)
						t=l;
				}
			}
		}
		cout<<m-t<<endl;
	}
}