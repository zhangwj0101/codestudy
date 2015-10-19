////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-21 22:56:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1084
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <algorithm>
using namespace std;
struct REC
{
	int i,p,t;
}rec[101];
int score[6];
int final[101];
int trans[5]={50,60,70,80,90};
bool cmp(REC a,REC b)
{
	if(a.p!=b.p)
		return a.p>b.p;
	else
		return a.t<b.t;
}
int main()
{
	int n,hh,mm,ss;
	int i,j,k;
	while(scanf("%d",&n),n>=0)
	{
		memset(score,0,sizeof(score));
		memset(rec,0,sizeof(rec));
		for(i=0;i<n;i++)
		{
			scanf("%d %d:%d:%d",&rec[i].p,&hh,&mm,&ss);
			rec[i].i=i;
			rec[i].t=hh*10000+mm*100+ss;
			score[rec[i].p]++;
		}
		sort(rec,rec+n,cmp);
		k=0;
		for(j=0;j<score[5];j++)
			final[rec[k++].i]=100;
		for(i=4;i>0;i--)
		{
			for(j=0;j<score[i]/2;j++)
			{
				final[rec[k++].i]=trans[i]+5;
			}
			for(;j<score[i];j++)
			{
				final[rec[k++].i]=trans[i];
			}
		}
		while(k<n)
			final[rec[k++].i]=50;
		for(i=0;i<n;i++)
			printf("%d\n",final[i]);
		puts("");
	}
	return 0;
}