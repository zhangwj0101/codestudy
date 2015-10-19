////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-06 11:38:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2024
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,x;
	char str[51];
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		x=0;
		gets(str);
		if((*str<='z'&&*str>='a')||(*str<='Z'&&*str>='A')||*str=='_')
			for(x=1,i=1;*(str+i)!='\0';i++)
				if(!((*(str+i)<='z'&&*(str+i)>='a')||(*(str+i)<='Z'&&*(str+i)>='A')||(*(str+i)>='0'&&*(str+i)<='9')||*(str+i)=='_'))
				{x=0;break;}
		if(x)
			printf("yes\n");
		else
			printf("no\n");
	}
}