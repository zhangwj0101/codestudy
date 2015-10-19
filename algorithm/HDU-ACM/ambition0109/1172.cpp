////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-26 20:08:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1172
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
/*
 * 1172.cpp
 *
 *  Created on: 2010-10-26
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

struct Guess{
	int num;
	int rs,rt;
}gs[110];
int n;

int Min(const int& a,const int& b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

bool Check(int num){
	int Hash[10],tHash[10];
	int tnum=num;
	for(int i=0;i<n;i++){
		int cnt=0;
		if(tnum%10==gs[i].num%10) cnt++;
		if((tnum%100)/10==(gs[i].num%100)/10) cnt++;
		if((tnum%1000)/100==(gs[i].num%1000)/100) cnt++;
		if(tnum/1000==gs[i].num/1000) cnt++;
		if(cnt==gs[i].rt){
			cnt=0;
			memset(Hash,0,sizeof(Hash));
			memset(tHash,0,sizeof(tHash));
			Hash[tnum%10]++;
			Hash[(tnum%100)/10]++;
			Hash[(tnum%1000)/100]++;
			Hash[tnum/1000]++;
			tHash[gs[i].num%10]++;
			tHash[(gs[i].num%100)/10]++;
			tHash[(gs[i].num%1000)/100]++;
			tHash[gs[i].num/1000]++;
			for(int j=0;j<10;j++){
				cnt+=Min(Hash[j],tHash[j]);
			}
			//printf("%d/%d\n",cnt,num);
			if(cnt!=gs[i].rs) return false;
		}else return false;
	}
	return true;
}

int main(){
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&gs[i].num,&gs[i].rs,&gs[i].rt);
		}
		int mem=-1,i;
		for(i=0;i<10000;i++){
			if(Check(i)){
				//puts("#");
				if(mem==-1) mem=i;
				else{
					//puts("*");
					puts("Not sure");
					break;
				}
			}
		}
		if(i==10000){
			if(mem==-1) puts("Not sure");
			else printf("%04d\n",mem);
		}
	}
}
