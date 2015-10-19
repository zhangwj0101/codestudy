////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-26 20:04:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1872
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct unit{
	string name;
	int score;
};
vector<unit> all;
vector<unit> asort;
vector<unit> msort;

int main()
{
	int n;
	while(cin>>n)
	{
		all.resize(n);
		asort.resize(n);
		int i=0;
		while(i<n){
			cin>>all[i].name>>all[i].score;
			i++;
		}
		msort=all;
		for(int i=0;i<n-1;i++){
			for(int j=n-2;j>=i;j--){
				if(msort[j].score<msort[j+1].score)
				{unit tt=msort[j];msort[j]=msort[j+1];msort[j+1]=tt;}
			}
		}
		i=0;
		while(i<n){
			cin>>asort[i].name>>asort[i].score;
			i++;
		}
		int min;
		min=(*asort.begin()).score;
		for(i=1;i<n;i++){
			if(min<asort[i].score) break;
			else min=asort[i].score;
		}
		if(i!=n){
			cout<<"Error"<<endl;
			for(i=0;i<n;i++)
				cout<<msort[i].name<<' '<<msort[i].score<<endl;
		}else{
			for(i=1;i<n;i++){
				if(msort[i].name!=asort[i].name) break;
			}
			if(i!=n){
				cout<<"Not Stable"<<endl;
				for(i=0;i<n;i++)
					cout<<msort[i].name<<' '<<msort[i].score<<endl;
			}else cout<<"Right"<<endl;
		}
	}
}