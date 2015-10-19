////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-17 16:07:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3456
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	string str;int t=0;
	while(getline(cin,str))
	{
		stringstream ss(str);
		string temp;
		while(ss>>temp)
		{
			if(temp.find("What")!=-1){
				string ans="Forty-two";
				while(ss>>temp){
					if(temp.find(".")!=-1){
						if(temp.find("What")!=-1) t=1;
						break;
					}
					if(temp.find('?')!=-1){
						if(temp.find('?')!=temp.length()-1){
							if(temp.find("What")==temp.find('?')+1) t=1;
							temp.erase(temp.begin()+temp.find("?")+1,temp.end());
						}
						ans+=" "+temp;ans[ans.length()-1]='.';
						cout<<ans<<endl;
						break;
					}else ans+=" "+temp;
				}
			}else{
				t=0;
				continue;
			}
		}
	}
}