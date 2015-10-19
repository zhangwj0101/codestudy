////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-23 16:06:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1297
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:420KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

string Add(string fNum,string sNum)
{
        if(fNum.length()<sNum.length()) fNum.swap(sNum);
        string Add("0");
    Add+=fNum;
        for(unsigned i=1;i<=fNum.length();i++)
                if(i<=sNum.length())
                        Add[Add.length()-i]+=sNum[sNum.length()-i]-'0';
        for(unsigned i=1;i<Add.length();i++)
        {
                if(Add[Add.length()-i]>'9')
                { Add[Add.length()-i]-=10;Add[Add.length()-i-1]+=1; }
        }
    while(Add[0]=='0') Add.erase(0,1);
        return Add;
}

string num[1001];
void main()
{
	num[0]="1";
	num[1]="1";
	num[2]="2";
	num[3]="4";
	for(int i=4;i<1001;i++){
		num[i]=Add(num[i-1],num[i-2]);
		num[i]=Add(num[i],num[i-4]);
	}
	int n;
	while(cin>>n){
		cout<<num[n]<<endl;
	}
}