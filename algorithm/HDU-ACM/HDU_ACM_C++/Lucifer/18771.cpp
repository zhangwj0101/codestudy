////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-09 17:34:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1877
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
void main()
{
	int m,i;
	unsigned int a,b,c;
	char str[33];
	while (scanf("%d",&m),m)
	{
		scanf("%u%u",&a,&b);
		c=a+b;
		for (i=0;c;c/=m,i++)
			str[i]='0'+(c%m);
		str[i]=0;
		strrev(str);
		puts(str[0]?str:"0");
	}
}
