////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 13:00:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1159
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1880KB
//////////////////System Comment End//////////////////
#include<iostream>
#define N 1001
#define M(a,b) ((a)>(b)?a:b)
using namespace std;
char a[N],b[N];
int	c[N][N];
int main()
{
	int al,bl,j,i;
	while(cin>>a>>b)
	{
		al=strlen(a);
		bl=strlen(b);
		for(i=0;i<al;i++)
			for(j=0;j<bl;j++)
				c[i][j]=0;
		for(i=0;i<al;i++)
			for(j=0;j<bl;j++)
			{
				if(a[i]==b[j])
					c[i+1][j+1]=c[i][j]+1;
				else
					c[i+1][j+1]=M(c[i][j+1],c[i+1][j]);
			}
		cout<<c[al][bl]<<endl;
	}
	return 0;
}