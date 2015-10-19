////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-04 17:10:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2132
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:6468KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

string sum[100001];

string Add(string fNum,string sNum)
{
	if(fNum.length()<sNum.length()) fNum.swap(sNum);
	string Add("0");
	Add+=fNum;
	for(unsigned i=1;i<=fNum.length();i++)
		if(i<=sNum.length())
			Add[Add.length()-i]+=sNum[sNum.length()-i]-'0';
	for(unsigned i=1;i<Add.length();i++){
		if(Add[Add.length()-i]>'9'){
			Add[Add.length()-i]-=10;Add[Add.length()-i-1]+=1;
		}
	}
	while(Add[0]=='0') Add.erase(0,1);
	return Add;
}
string itob(__int64 num)
{
	string Big("0000000000000000");
	for(unsigned i=Big.length()-1;num;i--)
	{
		Big[i]+=num%10;
		num/=10;
	}
	while(Big[0]=='0') Big.erase(0,1);
	return Big;
}

void main()
{
    int n,i=2;
    sum[0]="0";sum[1]="1";
    while(scanf("%d",&n),n>=0)
    {
        for(;i<=n;i++)
        {
            if(i%3)
                sum[i]=Add(sum[i-1],itob((__int64)i));
            else
                sum[i]=Add(sum[i-1],itob((__int64)i*(__int64)i*(__int64)i));
        }
        cout<<sum[n]<<endl;
    }
}