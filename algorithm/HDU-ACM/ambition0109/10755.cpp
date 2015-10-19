////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 15:58:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1075
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:55588KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNODE=500000;
const int BRANCH=26;

int Tree[MAXNODE][BRANCH],SIZE;
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
	if(word[Node][0]){
		printf("%s",word[Node]);
	}else{
		printf("%s",str);
	}
}

char sen[3005];
char temp[200];
char dir[15];

int main()
{
	scanf("%s",dir);
	while(scanf("%s",dir),strcmp(dir,"END")){
		char str[15];
		scanf("%s",str);
		Insert(str,dir);
	}
	scanf("%s",sen);
	getchar();
	while(gets(sen),strcmp(sen,"END")){
		int len=strlen(sen);
		sen[len++]=' ';
		sen[len]='\0';
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
