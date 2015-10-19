////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-19 11:52:17
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3079
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,k;
	char str[51];
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		scanf("%s",str);
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
				str[i]+=32;
			if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
				str[i]-=32;
		}
		printf("%s\n",str);
	}
}