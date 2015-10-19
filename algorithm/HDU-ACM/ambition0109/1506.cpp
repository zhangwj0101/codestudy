////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-16 17:18:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1506
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1352KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int right[100001],left[100001],num[100001];
void main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		num[n+1]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			left[i]=right[i]=i;
			while(left[i]>0&&num[left[i]-1]>=num[i])
				left[i]=left[left[i]-1];
		}
		__int64 max=0;
		for(int i=n;i>0;i--){
			while(right[i]<n&&num[right[i]+1]>=num[i])
				right[i]=right[right[i]+1];
			__int64 temp=(__int64)num[i]*(__int64)(right[i]-left[i]+1);
			if(temp>max)
				max=temp;
		}
		printf("%I64d\n",max);
	}
}