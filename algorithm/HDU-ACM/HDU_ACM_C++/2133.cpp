////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-24 21:46:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2133
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char w[7][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
struct Date{
  int year, month, day;
};
inline int leap(int year){
  return (year%4==0&&year%100!=0)||year%400==0;
}
inline int legal(Date a){
  if(a.month<0||a.month>12)
    return 0;
  if(a.month==2)
    return a.day>0 && a.day<=28+leap(a.year);
  return a.day>0 && a.day<=days[a.month-1];
}
int weekday(Date a){
  int tm = a.month>=3 ? (a.month-2) : (a.month+10);
  int ty = a.month>=3 ? a.year : (a.year-1);
  return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+a.day)%7;
}
int main()
{
	Date date;
	while(cin>>date.year>>date.month>>date.day)
	{
		if(!legal(date))cout<<"illegal\n";
		else cout<<w[weekday(date)]<<endl;
	}
    return 0;
}
/*

*/