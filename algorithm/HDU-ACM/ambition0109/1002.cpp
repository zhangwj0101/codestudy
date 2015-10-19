////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-01-26 10:50:06
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#define MAXSIZE 1002
main()
{
	int n,m,num,os,i,j;
	int la,lb;
	int va,vb,solve[MAXSIZE]={0};
	char a[MAXSIZE-1],b[MAXSIZE-1];
	for(scanf("%d",&n),j=0;j<n;j++)
	{
		os=num=MAXSIZE-1;
		scanf("%s %s",a,b);
		la=strlen(a),lb=strlen(b);
		while(la>lb?la:lb)
		{
			if((la-1)<0)	va=0;
			else	va=a[la-1]-'0';
			if((lb-1)<0)	vb = 0;
			else	vb=b[lb-1]-'0';
			solve[num]=va+vb;
			num--,la--,lb--;
		}
		m=strlen(a)>strlen(b)?(MAXSIZE-strlen(a)):(MAXSIZE-strlen(b));
		num=MAXSIZE-1;
		while(num+1)
		{
			if(solve[num]>9)
			{
				solve[num-1]++;
				solve[num]-=10;
			}
			num--;
		}
		printf("Case %d:\n%s + %s = ",j+1,a,b);
		for(i=0;i<MAXSIZE;i++)
		{
			if(solve[i]!=0)
			{
				os=i;
				break;
			}
		}
		for(i=os;i<MAXSIZE;i++)
		{
			printf("%d",solve[i]);
			solve[i]=0;
		}
		if(j!=n-1)	printf("\n");
		printf("\n");
	}
}