////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-26 19:19:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1736
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while(getline(cin,str)){
		int t=0;
		for(unsigned i=0;i<str.length();i++){
			if(str[i]==',') cout<<"£¬";
			else if(str[i]=='.') cout<<"¡£";
			else if(str[i]=='!') cout<<"£¡";
			else if(str[i]=='?') cout<<"£¿";
			else if(i+1<str.length()&&str[i]=='<'&&str[i+1]=='<'){
				cout<<"¡¶";i++;
			}else if(i+1<str.length()&&str[i]=='>'&&str[i+1]=='>'){
				cout<<"¡·";i++;
			}else if(str[i]=='\"'){
				t++;
				if(t&1) cout<<"¡°";
				else cout<<"¡±";
			}else if(str[i]==-95){
				t++;
				cout<<str[i];
			}else if(str[i]==-79){
				t++;
				cout<<str[i];
			}
			else cout<<str[i];
		}
		cout<<endl;
	}
}