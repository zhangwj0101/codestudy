////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-19 11:32:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1134
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

string num[101];

string Add(string fNum,string sNum)
{
        if(fNum.length()<sNum.length()) fNum.swap(sNum);
        string Add("0");
	Add+=fNum;
        for(unsigned i=1;i<=fNum.length();i++)
                if(i<=sNum.length())
                        Add[Add.length()-i]+=sNum[sNum.length()-i]-'0';
        for(i=1;i<Add.length();i++)
        {
                if(Add[Add.length()-i]>'9')
                { Add[Add.length()-i]-=10;Add[Add.length()-i-1]+=1; }
        }
	while(Add[0]=='0') Add.erase(0,1);
        return Add;
}
string Multiply(string fNum,string sNum)
{
        string Multiply,temp;
        if(fNum.length()<sNum.length()) fNum.swap(sNum);
        temp.resize(fNum.length()+sNum.length(),32);
        Multiply.resize(fNum.length()+sNum.length(),'0');
        for(unsigned i=1;i<=sNum.length();i++)
        {
                for(unsigned j=1;j<=fNum.length();j++)
                        temp[temp.length()-j-i+1]=(sNum[sNum.length()-i]-'0')*(fNum[fNum.length()-j]-'0')+32;
                for(j=1;j<=temp.length();j++)
                {
                        if(temp[temp.length()-j]>41)
                        {
                                while(temp[temp.length()-j]>41)
                                {
                                        temp[temp.length()-j]-=10;
                                        temp[temp.length()-j-1]+=1;
                                }
                        }
                        Multiply[Multiply.length()-j]+=temp[temp.length()-j]-32;
                        if(Multiply[temp.length()-j]>'9')
                        {
                                Multiply[Multiply.length()-j]-=10;
                                Multiply[Multiply.length()-j-1]+=1;
                        }
                }
                temp.replace(0,temp.length(),temp.length(),32);
        }
	while(Multiply[0]=='0') Multiply.erase(0,1);
        return Multiply;
}


void main()
{
	num[0]="1",num[1]="1",num[3]=5;
	for(int i=2;i<101;i++)
	{
		num[i]="0";
		for(int j=0;j<i;j++)
		num[i]=Add(Multiply(num[j],num[i-j-1]),num[i]);
	}
	int n;
	while(cin>>n,n+1) cout<<num[n]<<endl;
}