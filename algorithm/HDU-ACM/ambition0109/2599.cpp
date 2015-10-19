////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-16 09:43:20
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2599
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,i,j,pi,pj,k,t,num[101][101];
	char command[11];
	scanf("%d",&n);
	while(1)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&num[i][j]);
			while(1)
			{
				if(scanf("%s",command)==EOF) return;
				if(command[0]<='9'&&command[0]>='0')
				{n=atoi(command);break;}
				else if(command[0]=='S')
				{
					for(i=0;i<n;i++)
					{
						for(j=0;j<n;j++)
						{
							if(j) printf(" ");
							printf("%d",num[i][j]);
						}
						printf("\n");
					}
					printf("\n");
				}
				else if(command[0]=='N')
				{
					scanf("%d",&k);pi=0;pj=0;
					for(i=0;i<n;i++)
					{
						for(j=0;j<n;j++)
							if(num[i][j]==k)
							{pi=i;pj=j;break;}
							if(pi==i&&pj==j) break;
					}
					t=0;
					if(pi-1>=0) {printf("%d",num[pi-1][pj]);t=1;}
					if(pj-1>=0) {if(t)printf(" ");printf("%d",num[pi][pj-1]);t=1;}
					if(pj+1<n) {if(t)printf(" ");printf("%d",num[pi][pj+1]);t=1;}
					if(pi+1<n) {if(t)printf(" ");printf("%d",num[pi+1][pj]);t=1;}
					printf("\n");
				}
		}
	}
}