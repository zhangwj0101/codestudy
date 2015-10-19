////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-17 10:04:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1671
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2848KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=500000;
const int BRANCH=10;

int Tree[MAXNODE][BRANCH],SIZE;
bool Key[MAXNODE];
bool Insert(char *str) {
	int Node=0;bool tof=false;
	for (int i=0;str[i];i++){
		int c=str[i]-'0';
		if(Tree[Node][c]==-1){
			Tree[Node][c]=++SIZE;tof=true;
			memset(Tree[SIZE],-1,sizeof(Tree[SIZE]));
		}
		if(Key[Node]) return false;
		Node=Tree[Node][c];
	}
	Key[Node]=true;
	return tof;
}

void Trie(){
	memset(Tree[0],-1,sizeof(Tree[0]));
	SIZE=0;
}

char str[15];
int main()
{
	int t,n;bool tof;
	scanf("%d",&t);
	while(t--){
		memset(Key,false,sizeof(Key));
		Trie();tof=true;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",str);
			if(tof){
				tof=Insert(str);
			}
		}
		if(tof) puts("YES");
		else puts("NO");
	}
}
