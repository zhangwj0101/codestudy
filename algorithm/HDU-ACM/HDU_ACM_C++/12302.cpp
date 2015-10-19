////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-17 13:18:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1230
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
void print(int a[],int n)
{
	int i;
	for(i=n-1;i>=0;i--)
	{
		printf(",%d",a[i]);
	}
	puts("");
}

void rev(int a[],int n)
{
	int i,len;
	len=n/2;
	for(i=0;i<len;i++)
	{
		swap(a[i],a[n-1-i]);
	}
}
void cal(int a[],int b[],int n1,int n2)
{
	int i,carry,c2;
	for(carry=i=0;i<n2;i++)
	{
		c2=(a[i]+b[i]+carry)/prime[i];
		a[i]=(a[i]+b[i]+carry)%prime[i];
		carry=c2;
	}
	while((carry!=0)&&(i<n1))
	{
		c2=(a[i]+carry)/prime[i];
		a[i]=(a[i]+carry)%prime[i];
		carry=c2;
		i++;
	}
	if(carry!=0)
	{
		printf("%d",carry);
		print(a,n1);
	}
	else
	{
		printf("%d",a[n1-1]);
		print(a,n1-1);
	}
}
int main()
{
	int num[2][27];
	int i,j,n[2],temp,len;
	char c;
	int start[2];

	while(1)
	{
		i=0;
		n[0]=n[1]=0;
		memset(num,0,sizeof(num));
		while(scanf("%d%c",&temp,&c))
		{
			num[i][n[i]++]=temp;
			if(c==' ')
			{
				scanf("%d%c",&temp,&c);
				num[++i][0]=temp;
				n[i]++;
				if(c=='\n')
					break;
			}
			else if(c=='\n')
			{
				break;
			}
		}
		
		for(j=0;j<2;j++)
		{
			for(start[j]=0,i=0;(i<n[j])&&(num[j][i]==0);i++)
				start[j]++;
			n[j]-=start[j];
		}

		if(!n[0]||!n[1])
			break;

		rev(num[0]+start[0],n[0]);
		rev(num[1]+start[1],n[1]);
		
		if(n[0]>n[1])
			cal(num[0]+start[0],num[1]+start[1],n[0],n[1]);
		else
			cal(num[1]+start[1],num[0]+start[0],n[1],n[0]);

	}
	return 0;
}