////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-24 19:27:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2609
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:5760KB
//////////////////System Comment End//////////////////
/*
 * 2609.cpp
 *
 *  Created on: 2010-9-24
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=800000;
const int BRANCH=2;

int Max(int a,int b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

int Min(int a,int b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

int Tree[MAXN][BRANCH],SIZE;
bool Key[MAXN];
bool Insert(char *str,int len) {
	int Node=0;
	for (int i=0;i<len;i++){
		int c=str[i]-'0';
		if(!Tree[Node][c]){
			Tree[Node][c]=++SIZE;
			memset(Tree[SIZE],0,sizeof(Tree[SIZE]));
		}
		Node=Tree[Node][c];
	}
	if(Key[Node]) return false;
	else{
		Key[Node]=true;
		return true;
	}
}

void Trie(){
	memset(Key,false,sizeof(Key));
	memset(Tree[0],0,sizeof(Tree[0]));
	SIZE=0;
}

int MinState(char Str[],int len){
	int i=0,j=1,k=0;
	char temp[210];
	strcpy(temp,Str);
	strcpy(temp+len,Str);
	while(i < len && j < len)
	{
		k = 0;
		while(k < len && temp[i + k] == temp[j + k])
			k++;
		if(k >= len)
			break;
		if(temp[i + k] > temp[j + k])
			i=Max(i+k+1,j+1);
		else
			j=Max(i+1,j+k+1);
	}
	return Min(i,j);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		char str[110];
		int cnt=0;
		Trie();
		for(int i=0;i<n;i++){
			scanf("%s",str);
			int len=strlen(str);
			int Pos=MinState(str,len);
			char tmp[210];
			strcpy(tmp,str);
			strcpy(tmp+len,str);
			if(Insert(tmp+Pos,len)){
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
}
