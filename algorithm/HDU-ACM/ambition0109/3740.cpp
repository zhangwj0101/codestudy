////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-20 17:41:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3740
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:31560KB
//////////////////System Comment End//////////////////
/*
 * 3740.cpp
 *
 *  Created on: 2010-12-20
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

struct Node{
	char asc;
	vector<int> child;
	int cnt;
	Node(){}
	Node(char c):asc(c),cnt(0){}
}Tree[999999];
int SZ;

void Insert(char str[]){
	int N=0;
	for(int i=0;str[i];i++){
		if(str[i]==' ') continue;
		bool flag=false;
		for(unsigned j=0;j<Tree[N].child.size();j++){
			if(Tree[Tree[N].child[j]].asc==str[i]){
				N=Tree[N].child[j];
				flag=true;
				break;
			}
		}
		if(!flag){
			Tree[N].child.push_back(SZ);
			Tree[SZ]=Node(str[i]);
			Tree[N=SZ++].child.clear();
		}
		Tree[N].cnt++;
	}
}

int Max[1005];
char str[1005];

void Dfs(int idx,int step){
	if(Max[step]<Tree[idx].cnt){
		Max[step]=Tree[idx].cnt;
	}
	for(unsigned i=0;i<Tree[idx].child.size();i++){
		Dfs(Tree[idx].child[i],step+1);
	}
}

int main(){
	bool flag=false;
	while(gets(str)){
		Tree[0].child.clear(); SZ=1;
		for(unsigned i=0;i<strlen(str);i++){
			if(str[i]==' ') continue;
			Insert(str+i);
		}
		memset(Max,0,sizeof(Max));
		Dfs(0,0);
		if(flag) puts("");
		flag=true;
		for(int i=1;Max[i]>1;i++){
			printf("%d\n",Max[i]);
		}
		
	}
}
