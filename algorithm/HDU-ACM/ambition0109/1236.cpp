////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-21 14:34:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Score
{
	char id[25];
	int score;
}stu[1000];

bool cmp(const Score& a,const Score& b){
	if(a.score==b.score){
		if(strcmp(a.id,b.id)<0) return true;
		else return false;
	}
	return a.score>b.score;
}

int ans[10];
int main()
{
	int n,count;
	while(scanf("%d",&n),n)
	{
		int m,w;
		scanf("%d%d",&m,&w);
		for(int i=0;i<m;i++){
			scanf("%d",&ans[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%s %d",stu[i].id,&count);
			stu[i].score=0;
			for(int j=0;j<count;j++){
				int tid;
				scanf("%d",&tid);
				stu[i].score+=ans[tid-1];
			}
		}
		sort(stu,stu+n,cmp);
		int cnt=n;
		for(int i=n-1;i>=0;i--){
			if(stu[i].score>=w) break;
			cnt--;
		}
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++){
			printf("%s %d\n",stu[i].id,stu[i].score);
		}
	}
}