////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 11:08:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1702
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void main()
{
	int t;
	vector<int> num;
	cin>>t;
	while(t--)
	{
		int n;num.clear();
		string mod,cmd;
		cin>>n>>mod;
		while(n--)
		{
			cin>>cmd;
			if(cmd=="IN"){
				int temp;
				cin>>temp;
				num.push_back(temp);
			}else if(cmd=="OUT"){
				if(mod=="FILO"){
					if(num.empty())
						cout<<"None"<<endl;
					else{
						cout<<*(num.end()-1)<<endl;
						num.erase(num.end()-1);
					}
				}
				else if(mod=="FIFO"){
					if(num.empty())
						cout<<"None";
					else{
						cout<<*num.begin()<<endl;
						num.erase(num.begin());
					}
				}
			}
		}
	}
}