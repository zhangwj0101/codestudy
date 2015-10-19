////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-11 11:10:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2222
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:31420KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=1000000;
const int BRANCH=26;

int SIZE,SUM;
int Tree[MAXNODE][BRANCH];
int Key[MAXNODE];
char STR[1000050];
bool Hash[MAXNODE];
void Insert(char str[]) {
	int Node=0;
	for (int i=0;str[i];i++){
		int c=str[i]-'a';
		if(!Tree[Node][c]){
			Tree[Node][c]=++SIZE;
			memset(Tree[SIZE],0,sizeof(Tree[SIZE]));
		}
		Node=Tree[Node][c];
	}
	Key[Node]++;
}

void Init(){
	memset(Tree[0],0,sizeof(Tree[0]));
	memset(Key,0,sizeof(Key));
	memset(Hash,true,sizeof(Hash));
	SIZE=0;
}

int Que[MAXNODE],Fail[MAXNODE];
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

void Search(char str[],int len){
	SUM=0;
	for(int i=0,j=0;i<len;i++){
		if(Tree[j][str[i]-'a']){
			j=Tree[j][str[i]-'a'];
		}else{
			j=Fail[j];
		}
		int tmp=j;
		while(tmp&&Hash[tmp]){
			Hash[tmp]=false;
			if(Key[tmp]){
				SUM+=Key[tmp];
				Key[tmp]=0;
			}
			tmp=Fail[tmp];
		}
	}
}

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Init();
		char temp[55];
		for(int i=0;i<n;i++){
			scanf("%s",temp);
			Insert(temp);
		}
		GetFail();
		scanf("%s",STR);
		int ll=strlen(STR);
		Search(STR,ll);
		printf("%d\n",SUM);
	}
}