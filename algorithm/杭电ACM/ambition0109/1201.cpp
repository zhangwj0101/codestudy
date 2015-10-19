////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-08 19:19:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1201
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
/*
 * 1201.cpp
 *
 *  Created on: 2010-7-8
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

const int Month[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int dds(int year)
{
	bool leap=0;
	if(((year%4==0)&&(year%100!=0))||(year%400==0)) leap=1;
	if(leap) return 366;
	else return 365;
}
int days(int year,int month,int day)
{
	bool leap=0;
	if(((year%4==0)&&(year%100!=0))||(year%400==0)) leap=1;
	int yearday=day;
	for(int i=1;i<month;i++)
		yearday+=Month[leap][i];
	return yearday;
}

int main()
{
	int yy,mm,dd;
	int d,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d-%d-%d",&yy,&mm,&dd);
		if(mm==2&&dd==29){
			printf("-1\n");
			continue;
		}
		d=dds(yy)-days(yy,mm,dd);
		for(int y=yy+1;y<yy+18;y++)
			d+=dds(y);
		d+=days(yy+18,mm,dd);
		printf("%d\n",d);
	}
}
