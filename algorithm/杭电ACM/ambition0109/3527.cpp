////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-13 19:34:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3527
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> aname,nname;
int main()
{
	int a,n,m;
	while(cin>>a>>n>>m){
		aname.resize(a);
		nname.clear();
		for(int i=0;i<a;i++){
			cin>>aname[i];
		}
		for(int i=0;i<n;i++){
			string tname;
			cin>>tname;
			for(int j=0;j<a;j++){
				if(tname==aname[j]){
					nname.push_back(tname);
					break;
				}
			}
		}
		int len=int(nname.size());
		for(int i=0;i<m;i++){
			string tname;
			cin>>tname;
			for(int j=0;j<len;j++){
				if(tname==nname[j]){
					nname.erase(nname.begin()+j);
					len--;
					break;
				}
			}
		}
		if(len==0){
			cout<<"No enemy spy"<<endl;
		}else{
			cout<<nname[0];
			for(int i=1;i<len;i++){
				cout<<' '<<nname[i];
			}
			cout<<endl;
		}
	}
}