////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-21 10:17:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2896
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:25832KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=1000000;
const int BRANCH=96;

int Tree[MAXNODE][BRANCH],SIZE,n;
int Que[MAXNODE],Fail[MAXNODE];
int Key[MAXNODE];
char web[10010];
bool Hash[510];
void Insert(char *str,int t) {
	int Node=0;
	for (int i=0;str[i];i++){
		int c=str[i]-' ';
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
				//Key[v]=Key[Fail[v]];
			}else{
				Tree[p][i]=Tree[Fail[p]][i];
			}
		}
	}
}

bool Find(char* str,int t){
	bool tof=false;
	int len=strlen(str),Node=0;
	memset(Hash,false,sizeof(Hash));
	for(int i=0;i<len;i++){
		int c=str[i]-' ';
		while(Node&&!Tree[Node][c])
			Node=Fail[Tree[Node][c]];
		Node=Tree[Node][c];
		if(Key[Node]){
			tof=true;
			Hash[Key[Node]]=true;
		}
	}
	if(tof){
		printf("web %d:",t+1);
		for(int i=0;i<n;i++){
			if(Hash[i+1]){
				printf(" %d",i+1);
			}
		}
		puts("");
		return true;
	}
	return false;
}

int main()
{
	while(scanf("%d",&n)!=EOF){
		Trie();
		for(int i=0;i<n;i++){
			char str[210];
			scanf("%s",str);
			Insert(str,i+1);
		}
		GetFail();
		int m,count=0;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%s",web);
			if(Find(web,i)){
				count++;
			}
		}
		printf("total: %d\n",count);
	}
}
