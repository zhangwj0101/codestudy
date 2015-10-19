////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-19 13:49:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1133
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:748KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

string num[101][101];

string Add(string fNum,string sNum)
{
	if(fNum.length()<sNum.length()) fNum.swap(sNum);
	string Add("0");
	Add+=fNum;
	for(unsigned i=1;i<=fNum.length();i++)
		if(i<=sNum.length())
			Add[Add.length()-i]+=sNum[sNum.length()-i]-'0';
	for(i=1;i<Add.length();i++)
		if(Add[Add.length()-i]>'9')
		{ Add[Add.length()-i]-=10;Add[Add.length()-i-1]+=1; }
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
	int i,j,n,m;
	char t[4];
	string nn,mm;
	string ans;
	for(i=0;i<101;i++)
		for(j=0;j<101;j++)
			num[i][j]="0";
	for(i=0;i<101;i++)
		num[i][0]="1";
	for(i=1;i<101;i++)
	{
		for(j=1;j<=i;j++)
			num[i][j]=Add(num[i-1][j],num[i][j-1]);
	}
	int s=1;
	while(cin>>n>>m,n||m)
	{
		if(n>=m)
		{
			nn="1";
			for(i=2;i<=n;i++)
			{
				itoa(i,t,10);
				nn=Multiply(nn,t);
			}
			mm="1";
			for(i=2;i<=m;i++)
			{
				itoa(i,t,10);
				mm=Multiply(mm,t);
			}
			ans=Multiply(num[n][m],nn);
			ans=Multiply(ans,mm);
			cout<<"Test #"<<s++<<':'<<endl;
			cout<<ans<<endl;
		}
		else
		{
			cout<<"Test #"<<s++<<':'<<endl;
			cout<<"0"<<endl;
		}
	}
}