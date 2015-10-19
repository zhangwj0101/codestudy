////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-01-25 21:58:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,k,x,count[1000];
	char str[1000][16];
	while(scanf("%d",&n),n!=0)
	{
		scanf("%s",str[0]);
		count[0]=0;
		for(i=1;i<n;i++)
		{
			scanf("%s",str[i]);
			count[i]=0;
			for(j=i-1,x=0;j>=0;j--)
			{
				for(k=0;;k++)
					if(str[j][k]=='\0'&&str[i][k]=='\0')
					{
						count[i]=count[j]+1;
						x=1;break;
					}
					else
						if(str[j][k]!=str[i][k])
							break;
				if(x)
					break;
			}
		}
		k=0;
		for(i=0;i<n;i++)
			if(count[i]>count[k])
				k=i;
		printf("%s\n",str[k]);
	}
}