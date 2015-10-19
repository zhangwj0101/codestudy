////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-19 12:17:35
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,tmp,r;
	double value;
	char str[101];
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&m),getchar(),value=0;m>0;m--)
		{
			scanf("%s",str);
			for(i=0,tmp=0,r=0;str[i]!='\0';i++)
				if(str[i]!='-')
				{
					tmp+=str[i]-'0';
					if(str[i+1]!='-'&&str[i+1]!='\0')
						tmp=tmp*10;
					else
					{r+=tmp;tmp=0;}
				}
			value+=1./(double)r;
		}
		value=1./value;
		printf("%.2lf\n",value);
	}
}