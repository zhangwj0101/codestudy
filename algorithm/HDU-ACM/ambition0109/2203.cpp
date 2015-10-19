////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-02 21:07:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2203
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:308KB
//////////////////System Comment End//////////////////
/*
 * 2203.cpp
 *
 *  Created on: 2010-10-2
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;

int Fail[100010];
void GetFail(char str[]){
	Fail[0]=-1;
	int len=strlen(str);
	for(int i=1,j=-1;i<len;i++){
		while(j>=0&&str[j+1]!=str[i]){
			j=Fail[j];
		}
		if(str[j+1]==str[i]) j++;
		Fail[i]=j;
	}
}

int KMP(char strA[],char strB[]){
	int lenA=strlen(strA);
	int lenB=strlen(strB);
	for(int i=0,j=0;i<lenA;i++){
		while(j&&strA[i]!=strB[j]){
			j=Fail[j-1]+1;
		}
		if(strA[i]==strB[j]) j++;
		if(j==lenB) return i-lenB+1;
	}
	return -1;
}

char SA[100010],SB[100010];
char TMP[200010];
int main(){
	while(scanf("%s",SA)!=EOF){
		scanf("%s",SB);
		int len=strlen(SA);
		if(len<=int(strlen(SB))){
			puts("no");
			continue;
		}
		strcpy(TMP,SA);
		strcpy(TMP+len,SA);
		GetFail(SB);
		if(KMP(TMP,SB)!=-1){
			puts("yes");
		}else{
			puts("no");
		}
	}
}






