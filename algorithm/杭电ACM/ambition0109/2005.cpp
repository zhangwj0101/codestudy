////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 12:12:22
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
struct date
{
	int year;
	int month;
	int day;
	int yearday;
	char *monthname;
}date1;
main()
{
	int leap,i;
	static int month[2][13]={
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	while(scanf("%d/%d/%d",&date1.year,&date1.month,&date1.day)!=EOF)
	{
		i=date1.year;
		leap=0;
		if((i%4==0)&&(i%100!=0)||i%400==0) leap=1;
		date1.yearday=date1.day;
		for(i=1;i<date1.month;i++)
		date1.yearday+=month[leap][i];
		printf("%d\n",date1.yearday);
	}
}