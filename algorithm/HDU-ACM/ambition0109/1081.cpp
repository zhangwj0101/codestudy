////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-31 17:37:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1081
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int n;
int maxsum(int num[])
{
	int sum=-0x7fffffff,temp=0;
	for(int i=0;i<n;i++){
		temp+=num[i];
		if(temp>sum) sum=temp;
		if(temp<0) temp=0;
	}
	return sum;
}
int num[101][101];
void main()
{
	while(scanf("%d",&n)!=EOF){
		int max=-0x7fffffff;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				scanf("%d",&num[i][j]);
			int temp=maxsum(num[i]);
			if(temp>max) max=temp;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=0;k<n;k++)
					num[i][k]+=num[j][k];
				int temp=maxsum(num[i]);
				if(temp>max) max=temp;
			}
		}
		printf("%d\n",max);
	}
}