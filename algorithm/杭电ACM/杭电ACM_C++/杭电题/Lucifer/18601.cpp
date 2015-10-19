////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-04 23:00:39
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1860
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
void main()
{
	int i,count[128];
	char str1[6],str2[81];
	while (gets(str1))
	{
		if (!strcmp(str1,"#"))
			break;
		gets(str2);
		memset(count,0,sizeof(count));
		for (i=0;str2[i];i++)
			count[str2[i]]++;
		for (i=0;str1[i];i++)
			printf("%c %d\n",str1[i],count[str1[i]]);
	}
}