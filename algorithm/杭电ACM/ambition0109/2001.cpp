////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 10:31:16
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	float length,x1,x2,y1,y2;
	while(scanf("%f%f%f%f",&x1,&y1,&x2,&y2)!=EOF)
	{
		length=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		printf("%.2f\n",length);
	}
}