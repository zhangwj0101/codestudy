////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-28 21:36:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2133
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
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
int Days(Date a,Date b){
	int np=1;
	if(a.year>b.year){
		Swap(a,b);
		np=-1;
	}
	else if(a.year==b.year){
		if(a.month>b.month) Swap(a,b);
		else if(a.month==b.month){
			if(a.day>b.day) Swap(a,b);
		}
	}
	int days=Days(b)-Days(a);
	for(int year=a.year;year<b.year;year++){
		days+=Days(year);
	}
	return days*np;
}
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
int Week(Date date)
{
	Date Init;
	Init.set(1970,1,1);
	int days=Days(Init,date);
	while(days<0) days+=7000;
	int week=(days+4)%7;
	return week;
}

int main()
{
	Date A;
	while(scanf("%d%d%d",&A.year,&A.month,&A.day)!=EOF){
		if(!Check(A)) puts("illegal");
		else{
			int w=Week(A);
			if(w==0) puts("Sunday");
			else if(w==1) puts("Monday");
			else if(w==2) puts("Tuesday");
			else if(w==3) puts("Wednesday");
			else if(w==4) puts("Thursday");
			else if(w==5) puts("Friday");
			else if(w==6) puts("Saturday");
		}
	}
}
