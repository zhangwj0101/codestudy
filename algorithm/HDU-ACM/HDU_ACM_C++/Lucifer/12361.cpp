////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-10 10:41:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct record 
{
	char name[21];
	int score;
}Record,*PRec;

int compare( const void *arg1, const void *arg2 )
{
	if (((PRec) arg2)->score==((PRec) arg1)->score)
 		return strcmp(((PRec)arg1)->name,((PRec)arg2)->name);
	else
		return ((PRec)arg2)->score-((PRec)arg1)->score;
}

void main()
{
	Record rec[1000];
	char name[21];
	int n,i,j,m,g,mm,ss,tt;
	int s[10],k;
	while (scanf("%d",&n),n)
	{
		k=0;
		scanf("%d%d",&m,&g);
		for (i=0;i<m;i++)
			scanf("%d",&s[i]);
		for (i=0;i<n;i++)
		{
			scanf("%s",name);
			scanf("%d",&mm);
			ss=0;
			for (j=0;j<mm;j++)
			{
				scanf("%d",&tt);
				ss+=s[tt-1];
			}
			if (ss>=g)
			{
				strcpy(rec[k].name,name);
				rec[k].score=ss;
				k++;
			}
		}
		qsort(rec,k,sizeof(Record),compare);
		printf("%d\n",k);
		for (i=0;i<k;i++)
		{
			printf("%s %d\n",rec[i].name,rec[i].score);
		}
	}
}
