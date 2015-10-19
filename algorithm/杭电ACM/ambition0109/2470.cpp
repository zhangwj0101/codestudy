////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-20 16:14:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2470
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int cnt[105];
bool Map[105][105];
int main()
{
	int n,m,a,b,cas=0;
	while(scanf("%d%d%d%d",&n,&m,&a,&b),n||m||a||b){
		memset(Map,false,sizeof(Map));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<m;i++){
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			Map[t1][t2]=true;
			Map[t2][t1]=true;
			cnt[t1]++;
			cnt[t2]++;
		}
		int all=n,t=0;
		while(true){
			for(int i=0;i<n;i++){
				if(cnt[i]!=-1&&(cnt[i]<a||(all-cnt[i]-1<b))){
					cnt[i]=-1;
					all-=1;
					for(int j=0;j<n;j++){
						if(cnt[j]!=-1&&Map[i][j]){
							Map[j][i]=Map[i][j]=0;
							cnt[j]--;
						}
					}
				}
			}
			if(t==all){
				break;
			}
			t=all;
		}
		printf("Case #%d: %d\n",++cas,all);
	}
}