////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-13 14:24:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2719
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:168KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

char mod[8][4]={"%20","%21","%24","%25","%28","%29","%2a"};
int main(){
	char str[100];
	while(gets(str),strcmp(str,"#")){
		int len=strlen(str);
		for(int i=0;i<len;i++){
			if(str[i]==' ') printf("%s",mod[0]);
			else if(str[i]=='!') printf("%s",mod[1]);
			else if(str[i]=='$') printf("%s",mod[2]);
			else if(str[i]=='%') printf("%s",mod[3]);
			else if(str[i]=='(') printf("%s",mod[4]);
			else if(str[i]==')') printf("%s",mod[5]);
			else if(str[i]=='*') printf("%s",mod[6]);
			else printf("%c",str[i]);
		}
		puts("");
	}
}