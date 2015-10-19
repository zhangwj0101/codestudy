////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-01 20:53:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1308
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
/*
 * 1308.cpp
 *
 *  Created on: 2010-10-1
 *      Author: administrator
 */

#include<cstdio>
using namespace std;
struct Date{
    int year,month,day;
    void set(int ty,int tm,int td){
        year=ty;month=tm;day=td;
    }
};
const int Month[2][13]={
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}};

//交换两个日期
void Swap(Date& a,Date& b){
    Date tmp;
    tmp=a;a=b;b=tmp;
}
//判断某年是否为闰年
bool Leap(int year){
    return (((year%4==0)&&(year%100!=0))||(year%400==0));
}
//判断某年有多少天
int Days(int year){
    bool leap=Leap(year);
    return 365+leap;
}
//判断某天是某年的第几天
int Days(Date date){
    bool leap=Leap(date.year);
    int days=date.day;
    for(int i=1;i<date.month;i++)
        days+=Month[leap][i];
    return days;
}
//求某两天相差的天数
int Days(const Date& A,const Date& B){
    int np=1;
    Date a(A),b(B);
    if(a.year>b.year){
        Swap(a,b);
        np=-1;
    }else if(a.year==b.year){
        if(a.month>b.month){
        	Swap(a,b);
        	np=-1;
        }else if(a.month==b.month){
            if(a.day>b.day){
            	Swap(a,b);
            	np=-1;
            }
        }
    }
    int days=Days(b)-Days(a);
    for(int year=a.year;year<b.year;year++){
        days+=Days(year);
    }
    return days*np;
}
//判断一个日期是否合法
bool Check(Date date){
     bool leap=Leap(date.year);
     if(date.month<=0) return false;
     if(date.day<=0) return false;
     if(date.day>Month[leap][date.month]){
         return false;
     }
     return true;
}
//判断某天是星期几
int Weeka(Date date){
    Date Init;
    Init.set(1752,9,2);
    int days=Days(Init,date);
    while(days<0) days+=7000;
    int week=(days+3)%7;
    return week;
}
int Weekb(Date date)
{
    Date Init;
    Init.set(1752,9,14);
    int days=Days(Init,date);
    while(days<0) days+=7000;
    int week=(days+4)%7;
    return week;
}

char MonthN[][20]={"","January","February","March","April","May","June","July","August","September","October","November","Dececmber"};
char WeekN[][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main()
{
    Date A;
    while(scanf("%d%d%d",&A.month,&A.day,&A.year),A.month||A.day||A.year){
        if(!Check(A)){
        	printf("%d/%d/%d is an invalid date.\n",A.month,A.day,A.year);
        }
        else{
            Date Inita,Initb;
            Inita.set(1752,9,14);
            Initb.set(1752,9,2);
            if(Days(A,Initb)>=0){
            	int w=Weeka(A);
            	printf("%s %d, %d is a %s\n",MonthN[A.month],A.day,A.year,WeekN[w]);
            }else if(Days(Inita,A)>=0){
            	int w=Weekb(A);
            	printf("%s %d, %d is a %s\n",MonthN[A.month],A.day,A.year,WeekN[w]);
            }else{
            	printf("%d/%d/%d is an invalid date.\n",A.month,A.day,A.year);
            }

        }
    }
}
