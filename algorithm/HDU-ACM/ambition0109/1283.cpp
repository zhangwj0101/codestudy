////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-14 13:32:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
void main()
{
	int R1,R2,R3,M1,M2;
	string commond;
	while(cin>>M1>>M2)
	{
		cin>>commond;
		R1=R2=R3=0;
		for(unsigned i=0;i<commond.length();i++)
		{
			if(commond[i]=='A') R1=M1;
			else if(commond[i]=='B') R2=M2;
			else if(commond[i]=='C') M1=R3;
			else if(commond[i]=='D') M2=R3;
			else if(commond[i]=='E') R3=R1+R2;
			else if(commond[i]=='F') R3=R1-R2;
		}
		cout<<M1<<','<<M2<<endl;
	}
}