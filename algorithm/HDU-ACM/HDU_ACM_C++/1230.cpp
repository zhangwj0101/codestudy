////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-02-02 18:02:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1230
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int Prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
void main()
{
	char sym;
	int flag,temp,carry,carry2;
	int len[2],array[3][26];
	int min,max,i,j,k;
	while (1)
	{
		len[0]=len[1]=carry=flag=0;
		while (scanf("%d%c",&temp,&sym)==2)
		{
			array[flag][len[flag]++]=temp;
			if (sym==' ')
				flag++;
			else if(sym=='\n')
				break;
		}
		
		if ((array[0][0]==0)&&(len[0]==1))break;
		if ((array[1][0]==0)&&(len[1]==1))break;

		if (len[0]<len[1])
		{
			min=0;
			max=1;
		}
		else
		{
			min=1;
			max=0;
		}

		for(i=len[min]-1,j=len[max]-1,k=0;i>=0;i--,j--,k++)
		{
			carry2=(array[min][i]+array[max][j]+carry)/Prime[k];
			array[max][j]=(array[min][i]+array[max][j]+carry)%Prime[k];
			carry=carry2;
		}

		while (carry&&(j>=0))
		{
			carry2=(array[max][j]+carry)/Prime[k];
			array[max][j]=(array[max][j]+carry)%Prime[k];
			carry=carry2;
			k++;
			j--;
		}



		if (carry)
		{
			i=0;
			printf("%d",carry);
		}
		else
		{
			i=1;
			printf("%d",array[max][0]);
		}



		for (;i<len[max];i++)
		{
			printf(",%d",array[max][i]);
		}
		puts("");
	}
}