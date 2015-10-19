////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 10:00:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1982
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

void main()
{
	string str;
	int t;cin>>t;
	while(t--)
	{
		int num=0;cin>>str;
		for(unsigned i=0;i<str.length();i++){
			if(str[i]<='9'&&str[i]>='0'){
				num*=10;num+=str[i]-'0';
			}else if(str[i]=='-'&&num!=0){
				printf("%c",num+'A'-1);
				num=0;
			}else if(str[i]=='#'&&num!=0){
				printf("%c ",num+'A'-1);
				num=0;
			}else if(str[i]=='#'&&num==0)
				printf(" ");
		}
		if(num!=0)
		printf("%c\n",num+'A'-1);
		else printf("\n");
	}
}