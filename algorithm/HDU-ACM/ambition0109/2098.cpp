////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-27 17:16:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2098
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

bool num[10000];

void main()
{
	int n,i,j,count;
	memset(num,true,sizeof(num));
	num[0]=num[1]=false;
	for(i=2;i<10000;i++)
	{
		if(num[i])
			for(j=i*i;j<10000;j+=i)
				num[j]=false;
	}
	while(cin>>n,n)
	{
		for(i=2,count=0;i<n/2;i++)
		{
			if(num[i]&&num[n-i])
				count++;
		}
		printf("%d\n",count);
	}
}
