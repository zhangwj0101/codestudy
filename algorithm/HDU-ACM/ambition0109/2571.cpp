////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-03 12:58:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2571
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:460KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int num[21][1001];
int luck[21][1001];
void main()
{
	int n,x,y,i,j,k,max;
	for(cin>>n;n>0;n--)
	{
		cin>>y>>x;
		for(i=1;i<=y;i++)
			for(j=1;j<=x;j++)
				cin>>num[i][j];
		max=luck[1][1]=num[1][1];
		for(i=1;i<=y;i++)
			luck[i][1]=luck[i-1][1]+num[i][1];
		for(i=1;i<=y;i++)
			for(j=2;j<=x;j++)
				luck[i][j]=luck[i][1]+num[i][j];
		for(j=2;j<=x;j++)
		{
			if(luck[1][j]<luck[1][j-1]+num[1][j])
				luck[1][j]=luck[1][j-1]+num[1][j];
			for(k=2;j*k<=x;k++)
				if(luck[1][j*k]<luck[1][j]+num[1][j*k])
					luck[1][j*k]=luck[1][j]+num[1][j*k];
		}
		for(i=2;i<=y;i++)
			for(j=2;j<=x;j++)
			{
				max=luck[i-1][j]>luck[i][j-1]?luck[i-1][j]:luck[i][j-1];
				if(max+num[i][j]>luck[i][j])
					luck[i][j]=max+num[i][j];
				for(k=2;j*k<=x;k++)
					if(luck[i][j*k]<luck[i][j]+num[i][j*k])
						luck[i][j*k]=luck[i][j]+num[i][j*k];
			}
		cout<<luck[y][x]<<endl;
	}
}