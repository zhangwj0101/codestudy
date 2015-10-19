////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 17:29:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1862
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:1976KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define M 100010
struct REC
{
	char id[7];
	char name[9];
	char score;
}rec[M];
bool cmp1(REC a,REC b)
{
	return strcmp(a.id,b.id)<0;	
}
bool cmp2(REC a,REC b)
{
	int len=strcmp(a.name,b.name);
	if(len!=0)
		return len<0;
	return strcmp(a.id,b.id)<0;	
}
bool cmp3(REC a,REC b)
{
	if(a.score!=b.score)
		return a.score<b.score;
	return strcmp(a.id,b.id)<0;	
}
int main()
{
	int i,k;
	int n,c;
	k=0;
	while(scanf("%d%d",&n,&c),n)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d",rec[i].id,rec[i].name,&rec[i].score);
		}
		if(c==1)
			sort(rec,rec+n,cmp1);
		else if(c==2)
			sort(rec,rec+n,cmp2);
		else if(c==3)
			sort(rec,rec+n,cmp3);
		printf("Case %d:\n",++k);
		for(i=0;i<n;i++)
			printf("%s %s %d\n",rec[i].id,rec[i].name,rec[i].score);
	}
	return 0;
}