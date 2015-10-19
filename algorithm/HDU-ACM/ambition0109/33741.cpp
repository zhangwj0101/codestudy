////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 14:43:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3374
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:7032KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstring>
using namespace std;

char str[1000010];
int Fail[1000010];
char temp[2000010];

void GetFail(char num[],int m){
	Fail[0]=-1;
	for(int i=1,j=-1;i<m;i++){
		while(j>=0&&num[j+1]!=num[i]){
			j=Fail[j];
		}
		if(num[j+1]==num[i])j ++;
		Fail[i]=j;
	}
}

int State(char *Str,int len,bool t){
	int i=0,j=1,k=0;

	strcpy(temp,Str);
	strcpy(temp+len,Str);
	while(i < len && j < len)
	{
		k = 0;
		while(k < len && temp[i + k] == temp[j + k])
			k++;
		if(k >= len)
			break;
		if(t){
			if(temp[i + k] > temp[j + k])
				i = max(i + k + 1, j + 1);
			else
				j = max(i + 1, j + k + 1);
		}else{
			if(temp[i + k] < temp[j + k])
				i = max(i + k + 1, j + 1);
			else
				j = max(i + 1, j + k + 1);
		}
	}
	return min(i ,j);
}

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		int len=strlen(str);
		int k1=State(str,len,1);
		int k2=State(str,len,0);
		GetFail(str,len);
		int ans,loop=len-(Fail[len-1]+1); 
		if(len%loop){
			ans=1;
		}else{
			ans=len/loop;
		}
		printf("%d %d %d %d\n",k1+1,ans,k2+1,ans);
	}
}