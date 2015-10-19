////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-25 20:01:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1509
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:288KB
//////////////////System Comment End//////////////////
/*
 * 1509.cpp
 *
 *  Created on: 2010-9-25
 *      Author: administrator
 */

#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct MSG{
	string name;
	int id,num,pri;
	void set(string tname,int tid,int tnum,int tpri){
		name=tname;
		id=tid;num=tnum;pri=tpri;
	}
};

struct CMP{
	bool operator() (const MSG& a,const MSG& b){
		if(a.pri==b.pri) return a.id>b.id;
		else return a.pri>b.pri;
	}
};

priority_queue<MSG,vector<MSG>,CMP> QUE;
int main()
{
	string CMD;int ID=0;
	while(cin>>CMD){
		if(CMD=="GET"){
			if(QUE.empty()){
				cout<<"EMPTY QUEUE!"<<endl;
			}else{
				cout<<QUE.top().name<<' '<<QUE.top().num<<endl;
				QUE.pop();
			}
		}else if(CMD=="PUT"){
			MSG TMP;
			string tname;
			int tn,tp;
			cin>>tname>>tn>>tp;
			TMP.set(tname,ID++,tn,tp);
			QUE.push(TMP);
		}
	}
}
