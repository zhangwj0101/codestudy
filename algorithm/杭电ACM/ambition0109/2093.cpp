////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-30 19:26:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2093
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:2504KB
//////////////////System Comment End//////////////////
/*
 * 2093.cpp
 *
 *  Created on: 2010-8-30
 *      Author: ambition
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Stu{
	char name[15];
	int cnt;
	int time;
	Stu(){cnt=0;time=0;}
}stu[100000];

bool cmp(const Stu& a,const Stu& b){
	if(a.cnt==b.cnt){
		if(a.time==b.time){
			return strcmp(a.name,b.name)<0;
		}
		return a.time<b.time;
	}
	return a.cnt>b.cnt;
}

int pnlt;
int Proc(char str[])
{
	if(str[0]=='-') return 0;
	int len=strlen(str);
	int time=0,wa=0;
	for(int i=0;i<len;i++){
		char ch=str[i];
		if(ch<='9'&&ch>='0'){
			time*=10;
			time+=ch-'0';
		}else{
			for(i+=1;i<len;i++){
				ch=str[i];
				if(ch<='9'&&ch>='0'){
					wa*=10;
					wa+=ch-'0';
				}else{
					break;
				}
			}
		}
	}
	return time+pnlt*wa;
}

int main()
{
	int n,m=0;
	scanf("%d%d",&n,&pnlt);
	while(scanf("%s",stu[m].name)!=EOF){
		char tmp[15];
		for(int j=0;j<n;j++){
			scanf("%s",tmp);
			int time;
			time=Proc(tmp);
			if(time){
				stu[m].cnt++;
				stu[m].time+=time;
			}
		}
		m++;
	}
	sort(stu,stu+m,cmp);
	for(int i=0;i<m;i++){
		printf("%-10s %2d %4d\n",stu[i].name,stu[i].cnt,stu[i].time);
	}
}
