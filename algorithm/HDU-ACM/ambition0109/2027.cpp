////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-08 11:18:37
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2027
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,num[5];
	char str[101];
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		gets(str);
		for(i=0;i<5;i++)
			num[i]=0;
		for(i=0;str[i]!='\0';i++)
			if(str[i]=='a')
				num[0]++;
			else if(str[i]=='e')
				num[1]++;
			else if(str[i]=='i')
				num[2]++;
			else if(str[i]=='o')
				num[3]++;
			else if(str[i]=='u')
				num[4]++;
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",num[0],num[1],num[2],num[3],num[4]);
		if(n!=1)
			printf("\n");
	}
}