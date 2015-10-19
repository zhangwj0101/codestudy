////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-21 14:48:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2183
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<iomanip>
using namespace std;
int Matrix[22][22];
void main()
{
	int n;
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				Matrix[i][j]=0;
		Matrix[n/2+1][n/2]=1;
		int x=n/2+1,y=n/2;
		int xx,yy;
		for(int i=2;i<=n*n;i++)
		{
			xx=(x+1>=n)?0:x+1;
			yy=(y+1>=n)?0:y+1;
			if(Matrix[xx][yy]!=0)
			{
				xx=(x+2>=n)?x+2-n:x+2;
				yy=y;
			}
			Matrix[xx][yy]=i;
			x=xx;y=yy;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<setw(4)<<Matrix[i][j];
			cout<<endl;
		}
	}
}