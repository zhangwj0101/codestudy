////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-21 23:16:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1872
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <algorithm>
using namespace std;
struct REC
{
	int i;
	char name[51];
	int score;
}rec[600];
bool cmp(REC a,REC b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return a.i<b.i;
}
int main()
{
	int i,n,flag1,flag2;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s%d",rec[i].name,&rec[i].score);
			rec[i].i=i;
		}
		for(i=300;i<300+n;i++)
		{
			scanf("%s%d",rec[i].name,&rec[i].score);
		}
		sort(rec,rec+n,cmp);
		flag1=flag2=1;
		for(i=0;i<n;i++)
		{
			if(rec[i].score!=rec[i+300].score)
			{
				flag2=0;
				break;
			}
			if(flag1)
			{
				if(strcmp(rec[i].name,rec[i+300].name))
					flag1=0;
			}
		}
		if(flag2)
		{
			if(flag1)
			{
				puts("Right");
			}
			else
			{
				puts("Not Stable");
				for(i=0;i<n;i++)
					printf("%s %d\n",rec[i].name,rec[i].score);
			}
		}
		else
		{
			puts("Error");
			for(i=0;i<n;i++)
				printf("%s %d\n",rec[i].name,rec[i].score);
		}
	}
	return 0;
}