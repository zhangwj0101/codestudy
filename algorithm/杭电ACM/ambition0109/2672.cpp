////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-12 18:00:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2672
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

int Fib[1001];
void Fibonacci()
{
	Fib[1]=Fib[2]=1;
	for(int i=3;i<1001;i++)
		Fib[i]=(Fib[i-1]+Fib[i-2])%26;
}

void main()
{
	string str;Fibonacci();
	while(getline(cin,str))
	{
		for(unsigned i=0,j=1;i<str.length();i++){
			if(str[i]<='Z'&&str[i]>='A'){
				str[i]=(str[i]-'A'+Fib[j])%26+'A';
				j++;
			}
		}
		cout<<str<<endl;
	}
}