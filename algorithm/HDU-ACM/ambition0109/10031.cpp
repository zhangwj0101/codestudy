////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-09 09:22:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

void main()
{
    int t,n,num;
	scanf("%d",&t);
	for(int C=1;C<=t;C++)
	{
		scanf("%d",&n);
		int sum=-0x7fffffff,temp=0;
		int start=0,end=0,ts=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num);
			temp+=num;
			if(temp>sum) {sum=temp;start=ts;end=i;}
			if(temp<0) {temp=0;ts=i+1;}
		}
		if(C!=1) printf("\n");
		printf("Case %d:\n",C);
		printf("%d %d %d\n",sum,start+1,end+1);
	}
}