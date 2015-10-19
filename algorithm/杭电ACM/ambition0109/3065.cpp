////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-21 10:46:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3065
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:9156KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=1000000;
const int BRANCH=26;

int Tree[MAXNODE][BRANCH],SIZE,n;
int Que[MAXNODE],Fail[MAXNODE];
char word[1010][55];
int Key[MAXNODE];
char web[2000010];
int Hash[1010];
void Insert(char *str,int t) {
	int Node=0;
	for (int i=0;str[i];i++){
		int c=str[i]-'A';
		if(!Tree[Node][c]){
			Tree[Node][c]=++SIZE;
			memset(Tree[SIZE],0,sizeof(Tree[SIZE]));
		}
		Node=Tree[Node][c];
	}
	Key[Node]=t;
}

void Trie(){
	memset(Tree[0],0,sizeof(Tree[0]));
	memset(Key,0,sizeof(Key));
	memset(word,0,sizeof(word));
	SIZE=0;
}

void GetFail(){
	int *START=Que,*END=Que;
	for(int i=0;i<BRANCH;i++){
		if(Tree[0][i]){
			Fail[Tree[0][i]]= 0;
			*END++=Tree[0][i];
		}
	}
	while(START!=END){
		int p=*START++;
		for (int i=0;i<BRANCH;i++){
			if(Tree[p][i]){
				int v=Tree[p][i];
				*END++=v;
				Fail[v]=Tree[Fail[p]][i];
			}else{
				Tree[p][i]=Tree[Fail[p]][i];
			}
		}
	}
}

void Find(char* str){
	bool tof=false;
	int len=strlen(str),Node=0;
	memset(Hash,0,sizeof(Hash));
	for(int i=0;i<len;i++){
		if(str[i]<'A'||str[i]>'Z'){
			Node=0;
			continue;
		}
		int c=str[i]-'A';
		while(Node&&!Tree[Node][c])
			Node=Fail[Tree[Node][c]];
		Node=Tree[Node][c];
		if(Key[Node]){
			tof=true;
			Hash[Key[Node]]++;
		}
	}
	if(tof){
		for(int i=0;i<n;i++){
			if(Hash[i+1]){
				printf("%s: %d\n",word[i+1],Hash[i+1]);
			}
		}
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF){
		Trie();
		for(int i=0;i<n;i++){
			scanf("%s",word[i+1]);
			Insert(word[i+1],i+1);
		}
		GetFail();
		scanf("%s",web);
		Find(web);
	}
}
