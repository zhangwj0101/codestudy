////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-10 10:45:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1230
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};


void print(int n[],int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf(",%d",n[i]);
	}
	puts("");
}


void reverse(int digit[],int num)
{
	int i,temp;
	for(i=0;i<num/2;i++)
	{
		temp=digit[i];
		digit[i]=digit[num-i-1];
		digit[num-i-1]=temp;
	}
}
//将n2加到n1上
void add(int n1[],int n2[],int *num1,int *num2)
{
	int i,carry,temp;
	for(carry=i=0;i<*num2;i++)
	{
		temp=carry;
		carry=(n1[i]+n2[i]+carry)/prime[i];
		n1[i]=(n1[i]+n2[i]+temp)%prime[i];
	}
	while(carry!=0&&i<*num1)
	{
		temp=carry;
		carry=(n1[i]+carry)/prime[i];
		n1[i]=(n1[i]+temp)%prime[i];
		i++;
	}
	if (carry!=0)
	{
		printf("%d",carry);
		reverse(n1,*num1);
		print(n1,*num1);
	}
	else
	{
		reverse(n1,*num1);
		for(i=0;i<*num1;i++)
			if(n1[i]!=0)
			{
				printf("%d",n1[i]);
				break;
			}
		print(n1+i+1,*num1-i-1);
	}

}

int isZero(int digit[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(digit[i]!=0)
			break;
	}
	if(i==n)
		return 1;
	else
		return 0;
}

void main()
{
	int i;
	char c;
	int digit[2][26];
	int num[2];
	while(1)
	{
		i=0;
		num[0]=num[1]=0;
		memset(digit,0,52*4);
		while(scanf("%d%c",&digit[i][num[i]++],&c)==2)
		{
			if(c==' ')i++;
			else if(c=='\n')break;
		}
		if(isZero(digit[0],num[0]))break;
		if(isZero(digit[1],num[1]))break;

		reverse(digit[0],num[0]);
		reverse(digit[1],num[1]);
		if(num[0]<num[1])
		{
			add(digit[1],digit[0],num+1,num);
		}
		else
		{
			add(digit[0],digit[1],num,num+1);
		}
	}
}