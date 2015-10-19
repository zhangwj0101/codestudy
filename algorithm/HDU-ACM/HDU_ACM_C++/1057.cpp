////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-27 12:04:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1057
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
char C[5]=".!X#";
int main()
{
	int t,day,a[20][20],b[20][20],D[16],s,i,j,k,tt;
	cin>>t;
	for(tt=0;tt<t;tt++)
	{
		scanf("%d",&day);
		for(i=0;i<16;i++)
			scanf("%d",&D[i]);
		for(i=0;i<20;i++)
			for(j=0;j<20;j++)
				scanf("%d",&a[i][j]);
		for(k=0;k<day;k++)
		{
			for(i=0;i<20;i++)
			{
				for(j=0;j<20;j++)
				{
					s=a[i][j];
					if(i-1>=0)
						s+=a[i-1][j];
					if(j-1>=0)
						s+=a[i][j-1];
					if(i+1<20)
						s+=a[i+1][j];
					if(j+1<20)
						s+=a[i][j+1];
					b[i][j]=a[i][j]+D[s];
					if(b[i][j]>3)
						b[i][j]=3;
					else if(b[i][j]<0)
						b[i][j]=0;
				}
			}
			memcpy(a,b,sizeof(b));
		}
		if(tt)puts("");
		for(i=0;i<20;i++)
		{
			for(j=0;j<20;j++)
				putchar(C[b[i][j]]);
			puts("");
		}
	}
	return 0;
}