////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-15 12:09:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:340KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
struct REC
{
	char id[21];
	int score;
}rec[1000];
bool cmp(REC a,REC b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return (strcmp(a.id,b.id)<0);
}
int main()
{
	int n,m,g,mm;
	int sl[10];
	int i,k;
	int id;
	while(scanf("%d",&n),n)
	{
		k=0;
		scanf("%d%d",&m,&g);
		for(i=0;i<m;i++)
			scanf("%d",&sl[i]);
		
		for(i=0;i<n;i++)
		{
			scanf("%s",rec[k].id);
			scanf("%d",&mm);
			rec[k].score=0;
			while(mm--)
			{
				scanf("%d",&id);
				rec[k].score+=sl[id-1];
			}
			if(rec[k].score>=g)
				k++;
		}
		sort(rec,rec+k,cmp);
		printf("%d\n",k);
		for(i=0;i<k;i++)
		{
			printf("%s %d\n",rec[i].id,rec[i].score);
		}
	}
	return 0;
}
