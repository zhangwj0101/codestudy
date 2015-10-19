////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-16 18:02:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1800
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=1000000;
const int BRANCH=10;

int Tree[MAXNODE][BRANCH],SIZE;
int Key[MAXNODE];
int Insert(char *str) {
	int Node=0;
	for (int i=0;str[i];i++){
		int c=str[i]-'0';
		if(Tree[Node][c]==-1){
			Tree[Node][c]=++SIZE;
			memset(Tree[SIZE],-1,sizeof(Tree[SIZE]));
		}
		Node=Tree[Node][c];
	}
	Key[Node]++;
	return Key[Node];
}

void Trie(){
	memset(Tree[0],-1,sizeof(Tree[0]));
	SIZE=0;
}

char str[35];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(Key,0,sizeof(int)*(SIZE+1));
		Trie();
		int max=0;
		for(int i=0;i<n;i++){
			scanf("%s",str);
			int t=0;
			while(t<strlen(str)-1&&str[t]=='0'){
				t++;
			}
			int temp=Insert(str+t);
			if(temp>max)
				max=temp;
		}
		printf("%d\n",max);
	}
}