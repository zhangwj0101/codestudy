////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-28 19:18:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3724
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:1852KB
//////////////////System Comment End//////////////////
/*
 * tju_e.cpp
 *
 *  Created on: 2010-10-31
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

int Tree[100000][26],SIZE;
int Key[100000];
void Init(){
	memset(Tree[0],0,sizeof(Tree[0]));
	memset(Key,0,sizeof(Key));
	SIZE=0;
}

void Insert(char str[]){
	int Node=0;
	for(int i=0;str[i];i++){
		int c=str[i]-'a';
		if(!Tree[Node][c]){
			Tree[Node][c]=++SIZE;
			memset(Tree[SIZE],0,sizeof(Tree[SIZE]));
		}
		Node=Tree[Node][c];
		Key[Node]++;
	}
}

int Find(char str[],int len){
	int Node=0;
	for(int i=0;i<len;i++){
		int c=str[i]-'a';
		if(!Tree[Node][c]){
			return 0;
		}
		Node=Tree[Node][c];
	}
	return Key[Node];
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		Init();
		for(int i=0;i<n;i++){
			char str[35];
			scanf("%s",str);
			Insert(str);
		}
		int Sum=0;
		for(int i=0;i<m;i++){
			int t; char str[35];
			scanf("%d",&t);
			for(int j=0;j<t;j++){
				double tmp,ttmp;
				char word=NULL;
				scanf("%lf",&tmp);
				for(int k=0;k<7;k++){
					scanf("%lf",&ttmp);
					word*=2;
					if(ttmp/tmp>1.5){
						word+=1;
					}
				}
				//printf("@@ %d\n",word);
				str[j]=word;
			}
			str[t]='\0';
			Sum+=Find(str,t);
			//printf("## %s %d\n",str,Sum);
		}
		printf("%d\n",Sum);
	}
}
