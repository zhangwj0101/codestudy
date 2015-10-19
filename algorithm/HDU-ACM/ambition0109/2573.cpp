////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-07 20:15:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2573
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

bool Caps;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;Caps=false;
		cin>>n;
		for(int i=0;i<n;i++){
			string temp;
			cin>>temp;
			if(temp=="Shift"){
				cin>>temp;
				temp[0]-=32;
			}else if(temp=="Caps"){
				Caps^=1;
				continue;
			}
			if(Caps){
				if(temp[0]>='A'&&temp[0]<='Z'){
					temp[0]+=32;
				}else{
					temp[0]-=32;
				}
			}
			cout<<temp;
		}
		cout<<endl;
	}
}