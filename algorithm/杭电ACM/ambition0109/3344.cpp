////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-14 11:39:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3344
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,t,sum,x,y,k;
	char str[101][101],ans[101][101][8];
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&y,&x);
		for(i=0;i<y+1;i++)
			for(j=0;j<x+1;j++)
				str[i][j]='_';
		for(i=0;i<y;i++)
			for(j=0;j<x;j++)
			{getchar();scanf("%c",&str[i][j]);}
		for(i=0;i<y;i++)
			for(j=0;j<x;j++)
			{
				for(k=0;k<7;k++)
					ans[i][j][k]='X';
				ans[i][j][7]='\0';
			}
		for(i=0;i<y;i++)
			for(j=0;j<x;j++)
			{
				if(str[i][j]!='_')
					for(k=0;k<7;k++)
						ans[i][j][k]='.';
			}
		for(i=0;i<y;i++)
			for(j=0;j<x;j++)
			{
				if(str[i][j]!='_')
				{
					sum=str[i][j]-'0';
					t=j-1;
					for(j=j+1;str[i][j]!='_';j++)
						sum+=str[i][j]-'0';
					ans[i][t][6]=sum%10+'0';
					ans[i][t][5]=sum/10%10+'0';
					ans[i][t][4]=sum/100%10+'0';
					ans[i][t][3]='\\';
				}
			}
		for(j=0;j<x;j++)
			for(i=0;i<y;i++)
			{
				if(str[i][j]!='_')
				{
					sum=str[i][j]-'0';
					t=i-1;
					for(i=i+1;str[i][j]!='_';i++)
						sum+=str[i][j]-'0';
					ans[t][j][2]=sum%10+'0';
					ans[t][j][1]=sum/10%10+'0';
					ans[t][j][0]=sum/100%10+'0';
					ans[t][j][3]='\\';
				}
			}
		for(i=0;i<y;i++)
		{
			
			for(j=0;j<x;j++)
			{	
				printf("%s",ans[i][j]);
				if(j!=x-1)
					printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
}