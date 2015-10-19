////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-16 14:16:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1528
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*
 * 1528.cpp
 *
 *  Created on: 2010-11-16
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=60;

vector<int> Gra[N];
int mat[N];
bool Hash[N];

bool Find(int t){
	for(unsigned i=0;i<Gra[t].size();i++){
		int v=Gra[t][i];
		if(Hash[v]){
			Hash[v]=false;
			if(mat[v]==-1||Find(mat[v])){
				mat[v]=t;
				return true;
			}
		}
	}
	return false;
}

int BMM(){
	int Cnt=0;
	memset(mat,-1,sizeof(mat));
	for(int i=0;i<52;i++){
		memset(Hash,true,sizeof(Hash));
		if(Find(i)) Cnt++;
	}
	return Cnt;
}

const char val[15]="23456789TJQKA";
const char sign[5]="CDSH";
inline int H(char str[]){
	int num=0,i;
	for(i=0;i<13;i++){
		if(str[0]==val[i]){
			num=i*4;
			break;
		}
	}
	for(i=0;i<4;i++){
		if(str[1]==sign[i]){
			num+=i;
			break;
		}
	}
	return num;
}

int adam[30],eve[30];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		for(int i=0;i<52;i++){
			Gra[i].clear();
		}
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			char str[5];
			scanf("%s",str);
			adam[i]=H(str);
		}
		for(int i=0;i<n;i++){
			char str[5];
			scanf("%s",str);
			eve[i]=H(str);
		}
		for(int i=0;i<n;i++){
//			printf("%d:\n",eve[i]);
			for(int j=0;j<n;j++){
//				printf("- %d\n",adam[j]);
				if(adam[j]<eve[i]){
					Gra[eve[i]].push_back(adam[j]);
				}
			}
		}
		int Ans=BMM();
		printf("%d\n",Ans);
	}
}
