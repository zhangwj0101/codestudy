////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-07 17:06:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2100
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:292KB
//////////////////System Comment End//////////////////
/*
 * 2100.cpp
 *
 *  Created on: 2010-7-7
 *      Author: ambition
 */

#include<iostream>
#include<string>
using namespace std;

string Add(string fNum,string sNum)
{
		while(fNum[0]=='A') fNum.erase(0,1);
		while(sNum[0]=='A') sNum.erase(0,1);
        if(fNum.length()<sNum.length()) fNum.swap(sNum);
        string Add("A");
        Add+=fNum;
        for(unsigned i=1;i<=fNum.length();i++)
                if(i<=sNum.length())
                        Add[Add.length()-i]+=sNum[sNum.length()-i]-'A';
        for(unsigned i=1;i<Add.length();i++){
                if(Add[Add.length()-i]>'Z')
                { Add[Add.length()-i]-=26;Add[Add.length()-i-1]+=1; }
        }
        while(Add[0]=='A') Add.erase(0,1);
        return Add;
}
int main()
{
	string A,B;
	while(cin>>A>>B){
		cout<<Add(A,B)<<endl;
	}
}
