////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-12 19:38:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:172KB
//////////////////System Comment End//////////////////
/*
 * 2005.cpp
 *
 *  Created on: 2010-7-12
 *      Author: ambition
 */
#include<cstdio>
using namespace std;

const int Month[2][13]={
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}};
int days(int year)  //判断某年有多少天
{
        bool leap=0;
        if(((year%4==0)&&(year%100!=0))||(year%400==0)) leap=1;
        if(leap) return 366;
        else return 365;
}
int days(int year,int month,int day)  //判断某天是某年的第几天
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
	int y,m,d;
	while(scanf("%d/%d/%d",&y,&m,&d)!=EOF)
		printf("%d\n",days(y,m,d));
}
