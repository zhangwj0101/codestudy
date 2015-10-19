////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-15 09:16:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1865
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
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
string fib[201];
void Fib()
{
	fib[1]="1",fib[2]="2";
	for(int i=3;i<201;i++)
		fib[i]=Add(fib[i-1],fib[i-2]);
}
int main()
{
	int t;
	string str;
	cin>>t;
	Fib();
	while(t--)
	{
		cin>>str;
		cout<<fib[str.length()]<<endl;
	}
}