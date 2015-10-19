////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-04 23:01:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1862
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:2144KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
typedef struct record 
{
	char id[7];
	char name[9];
	int score;
}R;
int cmp1( const void *arg1, const void *arg2 )
{
	return strcmp(((R*)arg1)->id,((R*)arg2)->id);
}

int cmp2( const void *arg1, const void *arg2 )
{
	if(strcmp(((R*)arg1)->name,((R*)arg2)->name))
		return strcmp(((R*)arg1)->name,((R*)arg2)->name);
	else
		return strcmp(((R*)arg1)->id,((R*)arg2)->id);
}

int cmp3( const void *arg1, const void *arg2 )
{
	if (((R*)arg1)->score!=((R*)arg2)->score)
		return ((R*)arg1)->score-((R*)arg2)->score;
	else
		return strcmp(((R*)arg1)->id,((R*)arg2)->id);
}

void main()
{
	int n,c;
	int i,k;
	R *plist;
	k=1;
	while(scanf("%d%d",&n,&c),n)
	{
		plist=(R*)malloc(n*sizeof(R));
		for (i=0;i<n;i++)
			scanf("%s%s%d",plist[i].id,plist[i].name,&plist[i].score);
		switch(c)
		{
			case 1:
				qsort(plist,n,sizeof(R),cmp1);
				break;
			case 2:
				qsort(plist,n,sizeof(R),cmp2);
				break;
			case 3:
				qsort(plist,n,sizeof(R),cmp3);
				break;
		}
		printf("Case %d:\n",k++);
		for (i=0;i<n;i++)
			printf("%s %s %d\n",plist[i].id,plist[i].name,plist[i].score);

		free(plist);
		
	}
}