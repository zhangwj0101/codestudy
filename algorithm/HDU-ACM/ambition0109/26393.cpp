////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-19 18:28:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2639
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<memory>
using namespace std;
const int Max_Size=31;

int SetMerge(int SetA[],int lenA,int SetB[],int lenB,int SetAns[],int k)
{
	int Temp[Max_Size];
	memset(Temp,0,sizeof(Temp));
	int a=0,b=0,i=0;
	for(;i<k;i++){
		if(SetA[a]>SetB[b]){
			Temp[i]=SetA[a];
			a++;
		}else if(SetB[b]>SetA[a]){
			Temp[i]=SetB[b];
			b++;
		}else{
			Temp[i]=SetA[a];
			a++;b++;
		}
		if(a==lenA||b==lenB)
			break;
	}
	if(a==lenA){
		for(i++;i<k&&b<lenB;i++,b++)
			Temp[i]=SetB[b];
	}else if(b==lenB){
		for(i++;i<k&&a<lenA;i++,a++)
			Temp[i]=SetA[a];
	}
	for(int j=0;j<k;j++)
		SetAns[j]=Temp[j];
	return i;
}

int bag[1001][31];
int len[1001];int temp[1001];
int v[101],w[101];
void main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,av,ak;
		scanf("%d%d%d",&n,&av,&ak);
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++) scanf("%d",&v[i]);
		for(int i=0;i<=av;i++){
			memset(bag[i],0,sizeof(int)*ak);
			len[i]=1;
		}
		for(int i=1;i<=n;i++)
			for(int j=av;j>=v[i];j--){
				for(int k=0;k<len[j-v[i]];k++)
					temp[k]=bag[j-v[i]][k]+w[i];
				len[j]=SetMerge(temp,len[j-v[i]],bag[j],len[j],bag[j],ak);
			}
		if(len[av]>=ak) printf("%d\n",bag[av][ak-1]);
		else printf("0\n");
	}
}