////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-18 11:46:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2222
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:30452KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=1000000;
const int BRANCH=26;

int Tree[MAXNODE][BRANCH],SIZE,SUM;
int Key[MAXNODE];
char STR[1000050];
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
	Key[Node]++;
}

void Trie(){
	memset(Tree[0],0,sizeof(Tree[0]));
	memset(Key,0,sizeof(Key));
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
				/*Key[v]+=Key[Fail[v]];*/
			}else{
				Tree[p][i]=Tree[Fail[p]][i];
			}
		}
	}
}

void KMP(char *str,int len)
{
	SUM=0;
	for(int i=0,j=0;i<len;i++){
		if(Tree[j][str[i]-'a']==0){
			j=Fail[j];
		}else{
			j=Tree[j][str[i]-'a'];
		}
		int f=j;
		while(f){
			if(Key[f]){
				SUM+=Key[f];
				Key[f]=0;
			}
			f=Fail[f];
		}
	}
}

int main()
{
	int t,n;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		char temp[55];
		Trie();
		for(int i=0;i<n;i++){
			scanf("%s",temp);
			Insert(temp);
		}
		GetFail();
		scanf("%s",STR);
		int ll=strlen(STR);
		KMP(STR,ll);
		printf("%d\n",SUM);
	}
}