////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-01 21:16:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1862
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:2544KB
//////////////////System Comment End//////////////////
/*
 * 1826.cpp
 *
 *  Created on: 2010-10-1
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct unit{
	char id[8];
	char name[10];
	int score;
};

bool compare1( const unit& a, const unit& b )
{
	if(strcmp(a.id,b.id)<0) return true;
	else return false;
}
bool compare2( const unit& a, const unit& b )
{
	if(strcmp(a.name,b.name)<0) return true;
	else if(strcmp(a.name,b.name)>0) return false;
	else{
		if(strcmp(a.id,b.id)<0) return true;
		else return false;
	}
}
int compare3( const unit& a, const unit& b )
{
	if(a.score<b.score) return true;
	else if(a.score>b.score) return false;
	else{
		if(strcmp(a.id,b.id)<0) return true;
		else return false;
	}
}
unit stu[100001];
int main()
{
	int n,m,t=0;
	while(scanf("%d%d",&n,&m),n||m){
		for(int i=0;i<n;i++){
			scanf("%s %s %d",stu[i].id,stu[i].name,&stu[i].score);
		}
		printf("Case %d:\n",++t);
		if(m==1) sort(stu,stu+n,compare1);
		else if(m==2) sort(stu,stu+n,compare2);
		else if(m==3) sort(stu,stu+n,compare3);
		for(int i=0;i<n;i++){
			printf("%s %s %d\n",stu[i].id,stu[i].name,stu[i].score);
		}
	}
	return 0;
}
