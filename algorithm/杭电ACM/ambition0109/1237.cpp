////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-25 11:03:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1237
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<sstream>
#include<list>
using namespace std;

list<bool> sign;
list<double> num;
int main()
{
	string Formula;
	while(getline(cin,Formula),Formula!="0"){
		num.clear();
		sign.clear();
		stringstream ss(Formula);
		double tnum;char tsign;
		ss>>tnum;
		num.push_back(tnum);
		while(ss>>tsign>>tnum){
			if(tsign=='*') num.back()*=tnum;
			else if(tsign=='/') num.back()/=tnum;
			else if(tsign=='+'){
				num.push_back(tnum);
				sign.push_back(true);
			}else if(tsign=='-'){
				num.push_back(tnum);
				sign.push_back(false);
			}
		}
		while(!sign.empty()){
			double fnum=num.front();
			num.pop_front();
			if(sign.front()) num.front()+=fnum;
			else num.front()=fnum-num.front();
			sign.pop_front();
		}
		printf("%.2lf\n",num.front());
	}
}