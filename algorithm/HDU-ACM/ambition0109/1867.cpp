////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-16 11:02:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1867
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1156KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int Fail[2][100050];
void GetFail(char num[],int m,int t){
	Fail[t][0]=-1;
	for(int i=1,j=-1;i<m;i++){
		while(j>=0&&num[j+1]!=num[i]){
			j=Fail[t][j];
		}
		if(num[j+1]==num[i]) j++;
		Fail[t][i]=j;
	}
}
int KMP(char numA[],char numB[],int n,int m,int t){
	int j=0;
	for (int i=0;i<n;i++){
		while(j&&numB[j]!=numA[i]){
			j=Fail[t][j-1]+1;
		}
		if(numB[j]==numA[i]) j++;
		if(i!=n-1&&j==m) j=Fail[t][j-1]+1;
	}
	return j;
}

int main()
{
	char str1[100050],str2[100050];
	while(scanf("%s %s",str1,str2)!=EOF){
		int len1=int(strlen(str1));
		int len2=int(strlen(str2));
		GetFail(str1,len1,0);
		GetFail(str2,len2,1);
		int kmp1=KMP(str1,str2,len1,len2,1);
		int kmp2=KMP(str2,str1,len2,len1,0);
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