////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-17 16:39:54
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
					//	if(temp.find("What")!=-1) t=1;
						break;
					}
					if(temp.find('?')!=-1){
/*						if(temp.find('?')!=temp.length()-1){
							if(temp.find("What")==temp.find('?')+1) t=1;
							temp.erase(temp.begin()+temp.find("?")+1,temp.end());
						}*/
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

/*

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector <string> ans;
int main() {
    string str;
    while(getline(cin , str)) {
        ans.clear();
        int last = 0;
        for (int i = 0 ; i < str.size() ; i ++) {
            if(str[i] == '.' || str[i] == '?') {
                ans.push_back(str.substr(last,i-last+1));
                last = i + 1;
            }
            while(last < str.size() && str[last] == ' ') {
                last ++;
            }
        }
        for (int i = 0 ; i < ans.size() ; i ++) {
            if(ans[i].substr(0,7) == "What is" &&
                ans[i][ans[i].size()-1] == '?') {
                    ans[i].replace(0,4,"Forty-two");
                    ans[i].resize(ans[i].size()-1);
                    ans[i] += ".";
                    cout << ans[i] << endl;
            }
        }
    }
}

*/