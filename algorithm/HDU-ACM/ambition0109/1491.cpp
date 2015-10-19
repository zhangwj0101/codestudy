////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 17:48:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1491
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:292KB
//////////////////System Comment End//////////////////
/*
 * 1491.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<iostream>
using namespace std;

/*
 * 1555.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<iostream>
using namespace std;

const int Month[13]=
	{0,31,28,31,30,31,30,31,31,30,31,30,31};
int days(int month,int day)
{
	int yearday=day;
	for(int i=1;i<month;i++)
		yearday+=Month[i];
	return yearday;
}

int main()
{
	int dd=days(10,21),m,d,t;
	for(cin>>t;t--;)
	{
		cin>>m>>d;int dd2=days(m,d);
		if(dd2-dd<0) cout<<dd-dd2<<endl;
		else if(dd2-dd==0) cout<<"It's today!!"<<endl;
		else cout<<"What a pity, it has passed!"<<endl;
	}
}
