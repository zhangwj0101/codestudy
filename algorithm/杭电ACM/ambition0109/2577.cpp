////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-06 18:40:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2577
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

unsigned num[101][2];
void main()
{
	unsigned n;
	string str;
	for(cin>>n;n--;)
	{
		cin>>str;num[0][1]=2;
		if(str[0]<='Z'&&str[0]>='A') num[0][0]=2;
		else num[0][0]=1;
		for(unsigned i=1;i<str.length();i++){
			if(str[i]<='Z'&&str[i]>='A'){
				if(num[i-1][1]>num[i-1][0]+1)
					num[i][1]=num[i-1][0]+2;
				else num[i][1]=num[i-1][1]+1;
				if(num[i-1][1]>num[i-1][0])
					num[i][0]=num[i-1][0]+2;
				else num[i][0]=num[i-1][1]+2;
			}else if(str[i]<='z'&&str[i]>='a'){
				if(num[i-1][1]>num[i-1][0])
					num[i][1]=num[i-1][0]+2;
				else num[i][1]=num[i-1][1]+2;
				if(num[i-1][1]+1>num[i-1][0])
					num[i][0]=num[i-1][0]+1;
				else num[i][0]=num[i-1][1]+2;
			}
		}
		cout<<(num[str.length()-1][0]>num[str.length()-1][0]+1?num[str.length()-1][0]+1:num[str.length()-1][0])<<endl;
	}
}