////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-02 18:28:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <memory.h>

int binary[7]={1,2,4,8,16,32,64};
int value[351],bag[75001];
int main()
{
	int n,t,sum,half;
	while(scanf("%d",&n),n>=0){
		sum=t=0;
		for(int i=0,j=0,k;i<n;i++){
			scanf("%d%d",&value[j],&k);
			sum+=value[j]*k;
			int kk=1;k-=1;j++;
			while(k>binary[kk]){
				k-=binary[kk];
				value[j++]=value[t]*binary[kk++];
			}
			value[j++]=value[t]*k;
			t=j;
		}
		half=sum/2;
		memset(bag,0,sizeof(int)*(half+1));
		for(int i=0;i<t;i++){
			for(int j=half;j>=value[i];j--){
				if(bag[j-value[i]]+value[i]>bag[j])
					bag[j]=bag[j-value[i]]+value[i];
			}
		}
		printf("%d %d\n",sum-bag[half],bag[half]);
	}
}