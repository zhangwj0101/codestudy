////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-16 15:51:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1251
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:39380KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=2000000;
const int BRANCH=26;

int Tree[MAXNODE][BRANCH],SIZE;
int Key[MAXNODE];
void Insert(char *str) {
	int Node=0;
	for (int i=0;str[i];i++){
		int c=str[i]-'a';
		if(!Tree[Node][c]){
			Tree[Node][c]=++SIZE;
			memset(Tree[SIZE],0,sizeof(Tree[SIZE]));
		}
		Node=Tree[Node][c];
		Key[Node]++;
	}
}

int Find(char *str){
	int Node=0;
	for(int i=0;str[i];i++){
		int c=str[i]-'a';
		if(!Tree[Node][c]){
			return 0;
		}
		Node=Tree[Node][c];
	}
	return Key[Node];
}

void Trie(){
	memset(Tree[0],0,sizeof(Tree[0]));
	SIZE=0;
}

char s[15];
int main(){
	int i=0;
	Trie();
	while(gets(s)){
		if(strlen(s)==0) break;
		Insert(s);
	}
	while(gets(s)){
		printf("%d\n",Find(s));
	}
}