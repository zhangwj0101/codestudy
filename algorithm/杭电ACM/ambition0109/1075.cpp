////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 15:37:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1075
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:56576KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=1000000;
const int BRANCH=26;

int Tree[MAXNODE][BRANCH],SIZE;
bool key[MAXNODE];
char word[MAXNODE][15];
void Insert(char *str,char *dir) {
	int Node=0;
	for (int i=0;str[i];i++){
		int c=str[i]-'a';
		if(!Tree[Node][c]){
			Tree[Node][c]=++SIZE;
			memset(Tree[SIZE],0,sizeof(Tree[SIZE]));
		}
		Node=Tree[Node][c];
	}
	key[Node]=true;
	strcpy(word[Node],dir);
}

void Find(char *str){
	int Node=0;
	int len=strlen(str);
	for(int i=0;i<len;i++){
		int c=str[i]-'a';
		if(!Tree[Node][c]){
			printf("%s",str);
			return;
		}
		Node=Tree[Node][c];
	}
	if(key[Node]){
		printf("%s",word[Node]);
	}else{
		printf("%s",str);
	}
}
void Trie(){
	memset(Tree[0],0,sizeof(Tree[0]));
	memset(key,false,sizeof(key));
	SIZE=0;
}

char sen[3010];
char temp[3010];
char dir[15];

int main()
{
	Trie();
	while(scanf("%s",dir),strcmp(dir,"START"));
	while(scanf("%s",dir),strcmp(dir,"END")){
		char str[15];
		scanf("%s",str);
		Insert(str,dir);
	}
	while(scanf("%s",sen),strcmp(sen,"START"));
	getchar();
	while(gets(sen),strcmp(sen,"END")){
		int len=strlen(sen);
		sen[len++]=' ';
		sen[len]='\0';
		//puts(sen);
		for(int i=0,t=0;i<len;i++){
			if(sen[i]<'a'||sen[i]>'z'){
				temp[t]='\0';
				if(temp[0]){
					Find(temp);
				}
				temp[0]='\0';
				if(i!=len-1){
					printf("%c",sen[i]);
				}
				t=0;
			}else{
				temp[t++]=sen[i];
			}
		}
		puts("");
	}
}
