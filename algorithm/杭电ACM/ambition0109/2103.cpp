////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-15 11:50:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2103
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int bog;
void main()
{
	int t,n,m;cin>>t;
	while(t--){
		cin>>n>>m;int i;
		for(i=0;i<n&&i<m;i++){
			cin>>bog;
			if(bog){
				i++;
				break;
			}
		}
		int sum=0;
		int tt=1;
		for(;i<m;i++){
			cin>>bog;
			sum+=tt;
			tt+=tt;
		}
		if(sum==0) cout<<sum<<" RMB"<<endl;
		else cout<<sum<<"0000 RMB"<<endl;
	}
}