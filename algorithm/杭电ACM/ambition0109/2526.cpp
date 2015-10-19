////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-28 18:02:07
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2526
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1168KB
//////////////////System Comment End//////////////////
#include<stdio.h>
char note[1001][1001];
char mode[8];
main()
{
	int n,m,t,i,j,l;
	char ch;
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&t),i=0;i<8;i++)
		{
			scanf("%d %c",&m,&ch);
			if(m==0) mode[0]=ch;
			else if(m==1) mode[1]=ch;
			else if(m==10) mode[2]=ch;
			else if(m==11) mode[3]=ch;
			else if(m==100) mode[4]=ch;
			else if(m==101) mode[5]=ch;
			else if(m==110) mode[6]=ch;
			else if(m==111) mode[7]=ch;
		}
		getchar();scanf("%s",note[0]);
		for(i=0;note[0][i]!='\0';i++);l=i;
		printf("%s\n",note[0]);
		for(i=1;i<t;i++)
		{
			for(j=0;j<l;j++)
			{
				if(j==0)
					m=10*(note[i-1][0]-'0')+(note[i-1][1]-'0');
				else if(j==l-1)
					m=100*(note[i-1][j-1]-'0')+10*(note[i-1][j]-'0');
				else
					m=100*(note[i-1][j-1]-'0')+10*(note[i-1][j]-'0')+(note[i-1][j+1]-'0');
				if(m==0) note[i][j]=mode[0];
				else if(m==1) note[i][j]=mode[1];
				else if(m==10) note[i][j]=mode[2];
				else if(m==11) note[i][j]=mode[3];
				else if(m==100) note[i][j]=mode[4];
				else if(m==101) note[i][j]=mode[5];
				else if(m==110) note[i][j]=mode[6];
				else if(m==111) note[i][j]=mode[7];
			}
			note[i][j]='\0';
			printf("%s\n",note[i]);
		}
	}
}