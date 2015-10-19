////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-15 17:13:22
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{ 
	int icase,t,n,i,j,a[1000],change;
	scanf("%d",&icase);
	for(t=0;t<icase;t++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(a[i]>a[j])
				 {change=a[i];a[i]=a[j];a[j]=change;}
		for(j=0;j<n;j++)
		{
			printf("%d",a[j]);
			if(j!=n-1)
				printf(" ");
		}
		printf("\n");
	}
 } 
