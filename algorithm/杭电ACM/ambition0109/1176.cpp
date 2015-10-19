////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-26 13:04:53
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1176
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:4520KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[100000][11]={0};
main()
{
	int n,m,i,j,x,y,max;
	while(scanf("%d",&n),n)
	{
		for(i=0,m=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			num[y-1][x]+=1;
			if(y>m)
				m=y;
		}
		for(i=m-1;i>0;i--)
		{
			num[i-1][0]+=num[i][0]>num[i][1]?num[i][0]:num[i][1];
			num[i-1][10]+=num[i][10]>num[i][9]?num[i][10]:num[i][9];
			for(j=1;j<10;j++)
			{
				max=num[i][j-1]>num[i][j]?num[i][j-1]:num[i][j];
				max=num[i][j+1]>max?num[i][j+1]:max;
				num[i-1][j]+=max;
			}
		}
		max=num[0][4]>num[0][5]?num[0][4]:num[0][5];
		max=num[0][6]>max?num[0][6]:max;
		printf("%d\n",max);
		for(y=0;y<m;y++)
			for(x=0;x<11;x++)
				num[y][x]=0;
	}
}
