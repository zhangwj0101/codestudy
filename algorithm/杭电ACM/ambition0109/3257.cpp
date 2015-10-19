////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-26 16:44:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3257
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int num[150][5],t[7]={0x1,0x2,0x4,0x8,0x10,0x20,0x40};
void main()
{
	int n,m,i,ii,j,k;
	for(scanf("%d",&n),ii=0;ii<n;ii++)
	{
		for(scanf("%d",&m),i=0;i<m;i++)
			scanf("%x%x%x%x%x",&num[i][0],&num[i][1],&num[i][2],&num[i][3],&num[i][4]);
		printf("Case %d:\n\n",ii+1);
		for(k=0;k<7;k++)
		{
			for(i=0;i<m;i++)
			{
				if(i) printf(" ");
				for(j=0;j<5;j++)
				{
					
					if(num[i][j]&t[k])
						printf("#");
					else printf(" ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}