////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-17 09:28:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2870
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:11980KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int num1[1001][1001];
int num2[1001][1001];
int num3[1001][1001];
int L1[1001],R1[1001];
int L2[1001],R2[1001];
int L3[1001],R3[1001];
void main()
{
	int n,m;char ch;int max;
	while(scanf("%d%d",&n,&m)!=EOF){
		max=0;
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=m;j++){
				scanf("%c",&ch);
				if(ch=='a'||ch=='w'||ch=='y'||ch=='z')
					num1[i][j]=num1[i-1][j]+1;
				else num1[i][j]=0;
				if(ch=='b'||ch=='w'||ch=='x'||ch=='z')
					num2[i][j]=num2[i-1][j]+1;
				else num2[i][j]=0;
				if(ch=='c'||ch=='x'||ch=='y'||ch=='z')
					num3[i][j]=num3[i-1][j]+1;
				else num3[i][j]=0;
				L1[j]=L2[j]=L3[j]=j;
				while(L1[j]>0&&num1[i][L1[j]-1]>=num1[i][j])
					L1[j]=L1[L1[j]-1];
				while(L2[j]>0&&num2[i][L2[j]-1]>=num2[i][j])
					L2[j]=L2[L2[j]-1];
				while(L3[j]>0&&num3[i][L3[j]-1]>=num3[i][j])
					L3[j]=L3[L3[j]-1];
			}
			for(int j=m;j>0;j--){
				R1[j]=R2[j]=R3[j]=j;
				while(R1[j]<m&&num1[i][R1[j]+1]>=num1[i][j])
					R1[j]=R1[R1[j]+1];
				while(R2[j]<m&&num2[i][R2[j]+1]>=num2[i][j])
					R2[j]=R2[R2[j]+1];
				while(R3[j]<m&&num3[i][R3[j]+1]>=num3[i][j])
					R3[j]=R3[R3[j]+1];
				int temp=num1[i][j]*(R1[j]-L1[j]+1);
				if(temp>max) max=temp;
				temp=num2[i][j]*(R2[j]-L2[j]+1);
				if(temp>max) max=temp;
				temp=num3[i][j]*(R3[j]-L3[j]+1);
				if(temp>max) max=temp;
			}
		}
		printf("%d\n",max);
	}
}