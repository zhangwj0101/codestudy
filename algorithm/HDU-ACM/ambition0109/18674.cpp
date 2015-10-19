////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-16 11:11:46
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1867
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:736KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>

int Fail[100010];
void GetFail(char num[],int m){
	int i,j;Fail[0]=-1;
	for(i=1,j=-1;i<m;i++){
		while(j>=0&&num[j+1]!=num[i]){
			j=Fail[j];
		}
		if(num[j+1]==num[i]) j++;
		Fail[i]=j;
	}
}
int KMP(char numA[],char numB[],int n,int m){
	int i,j=0;
	GetFail(numB,m);
	for (i=0;i<n;i++){
		while(j&&numB[j]!=numA[i]){
			j=Fail[j-1]+1;
		}
		if(numB[j]==numA[i]) j++;
		if(i!=n-1&&j==m) j=Fail[j-1]+1;
	}
	return j;
}

int main()
{
	char str1[100010],str2[100010];
	int len1,len2,kmp1,kmp2;
	while(scanf("%s %s",str1,str2)!=EOF){
		len1=(int)strlen(str1);
		len2=(int)strlen(str2);
		kmp1=KMP(str1,str2,len1,len2);
		kmp2=KMP(str2,str1,len2,len1);
		if(kmp1==kmp2){
			if(strcmp(str1,str2)>=0){
				printf("%s%s\n",str2,str1+kmp2);
			}else{
				printf("%s%s\n",str1,str2+kmp1);
			}
		}else if(kmp1>kmp2){
			printf("%s%s\n",str1,str2+kmp1);
		}else if(kmp2>kmp1){
			printf("%s%s\n",str2,str1+kmp2);
		}
	}
}