////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 19:40:08
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2000
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	char ch[3],tmp;
	while(scanf("%s",ch)!=EOF)
	{
		if(ch[0]>ch[1])
			tmp=ch[0],ch[0]=ch[1],ch[1]=tmp;
		if(ch[0]>ch[2])
			tmp=ch[0],ch[0]=ch[2],ch[2]=tmp;
		if(ch[1]>ch[2])
			tmp=ch[1],ch[1]=ch[2],ch[2]=tmp;
		printf("%c %c %c\n",ch[0],ch[1],ch[2]);
	}
}