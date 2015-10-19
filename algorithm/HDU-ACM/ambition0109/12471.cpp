////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 17:39:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1247
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:5100KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=1000000;
const int BRANCH=26;

int Tree[MAXNODE][BRANCH],SIZE;
bool Key[MAXNODE];
void Insert(char *str) {
	int Node=0;
	for (int i=0;str[i];i++){
		int c=str[i]-'a';
		if(!Tree[Node][c]){
			Tree[Node][c]=++SIZE;
			memset(Tree[SIZE],0,sizeof(Tree[SIZE]));
		}
		Node=Tree[Node][c];
	}
	Key[Node]=true;
}
bool Find(char *str){
	int Nodef=0,Nodes;
	int len=strlen(str);
	for(int i=0;i<len-1;i++){
		int c=str[i]-'a';
		Nodef=Tree[Nodef][c];
		if(Key[Nodef]){
			int j;Nodes=0;
			for(j=i+1;j<len;j++){
				int cc=str[j]-'a';
				if(Tree[Nodes][cc]){
					Nodes=Tree[Nodes][cc];
				}else break;
			}
			if(j==len&&Key[Nodes])
				return true;
		}
	}
	return false;
}
//void Trie(){
//	memset(Tree[0],0,sizeof(Tree[0]));
//	memset(Key,0,sizeof(Key));
//	SIZE=0;
//}

char word[50010][20];
int main(){
	int t=0;/*Trie();*/
	while(scanf("%s",word[t])!=EOF){
		Insert(word[t++]);
	}
	for(int i=0;i<t;i++){
		if(Find(word[i])){
			puts(word[i]);
		}
	}
}