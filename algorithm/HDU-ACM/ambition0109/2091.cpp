////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-18 17:27:43
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2091
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,line,x=0;
	char ch;
	while(scanf("%c",&ch),ch!='@')
	{
		scanf("%d",&n);
		getchar();
		if(x)
			printf("\n");
		x=1;
		for(line=0;line<n;line++)
		{
			for(i=n-line;i>1;i--)
				printf(" ");
			printf("%c",ch);
			if(line==n-1)
				for(i=line*2;i>0;i--)
					printf("%c",ch);
			else if(line)
			{
				for(i=line*2-1;i>0;i--)
					printf(" ");
				printf("%c",ch);
			}
			printf("\n");
		}
	}
}