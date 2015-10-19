////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-02 22:28:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int a,b,n;
	double num;
	char ch;
	for(scanf("%d",&n);n>0;n--)
	{
		getchar();
		scanf("%c%d%d",&ch,&a,&b);
		if(ch=='+')
			num=a+b;
		else if(ch=='-')
			num=a-b;
		else if(ch=='*')
			num=a*b;
		else if(ch=='/')
			num=(double)a/(double)b;
		if(num==(int)num)
			printf("%.0lf\n",num);
		else
			printf("%.2lf\n",num);
	}
}