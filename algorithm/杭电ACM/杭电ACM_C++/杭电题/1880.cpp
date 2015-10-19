////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-09 17:37:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1880
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:11956KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <search.h>

#define M 100000
char curse[M+1][23];
char def[M+1][81];
typedef struct rec 
{
	int cur;
	int def;
}R;

R rec[M];
R rrec[M];

int cmp1( const void *arg1, const void *arg2 )
{
	return strcmp(curse[((R*)arg1)->cur],curse[((R*)arg2)->cur]);
}

int cmp2( const void *arg1, const void *arg2 )
{
	return strcmp(def[((R*)arg1)->def],def[((R*)arg2)->def]);
}

void main()
{
	char str[110];
	int i,k=0,n;
	R *result;
	R temp;
	while (gets(str),strcmp(str,"@END@"))
	{
		for (i=0;str[i]!=' ';i++);
		str[i-1]=0;
		strcpy(curse[k],str+1);
		strcpy(def[k],str+i+1);
		rrec[k].cur=rrec[k].def=rec[k].cur=rec[k].def=k;
		k++;
	}
	qsort(rec,k,sizeof(R),cmp1);
	qsort(rrec,k,sizeof(R),cmp2);
	scanf("%d",&n);
	getchar();
	for (i=0;i<n;i++)
	{
		gets(str);
		temp.cur=M;
		temp.def=M;
		if (str[0]=='[')
		{
			str[strlen(str)-1]=0;
			strcpy(curse[M],str+1);
			result=(R*)bsearch(&temp,rec,k,sizeof(R),cmp1);
			puts(result?def[result->cur]:"what?");
		}
		else
		{
			strcpy(def[M],str);
			result=(R*)bsearch(&temp,rrec,k,sizeof(R),cmp2);
			puts(result?curse[result->def]:"what?");
		}
	}
}