////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-24 15:45:29
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1159
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1176KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,num[500][500];
	char str[2][501];
	while(scanf("%s %s",str[0],str[1])!=EOF)
	{
		for(i=0;str[0][i]!='\0';i++)
			if(str[0][i]==str[1][0])
			{
				for(;str[0][i]!='\0';i++)
					num[0][i]=1;
				break;
			}
			else
				num[0][i]=0;
		for(i=0;str[1][i]!='\0';i++)
			if(str[1][i]==str[0][0])
			{
				for(;str[1][i]!='\0';i++)
					num[i][0]=1;
				break;
			}
			else
				num[i][0]=0;
		for(i=1;str[1][i]!='\0';i++)
			for(j=1;str[0][j]!='\0';j++)
				if(str[1][i]==str[0][j])
					num[i][j]=num[i-1][j-1]+1;
				else
					num[i][j]=num[i-1][j]>num[i][j-1]?num[i-1][j]:num[i][j-1];
		printf("%d\n",num[i-1][j-1]);
	}
}