////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-26 17:35:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3573
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int maybe[12][3]={{2,0,1},{2,1,0},{0,0,2},{3,0,0},{0,1,1},{0,2,0},{1,0,1},{1,1,0},{2,0,0},{0,0,1},{0,1,0},{1,0,0}};


int num[3];
int main()
{
	int t,c=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&num[0],&num[1],&num[2]);
		int count=0;
		for(int i=0;i<12;i++){
			if(num[0]<maybe[i][0]||num[1]<maybe[i][1]||num[2]<maybe[i][2]){
				continue;
			}
			int max=1000000;
			if(maybe[i][0]){
				max=num[0]/maybe[i][0];
			}
			int temp;
			if(maybe[i][1]){
				temp=num[1]/maybe[i][1];
				if(temp<max) max=temp;
			}
			if(maybe[i][2]){
				temp=num[2]/maybe[i][2];
				if(temp<max) max=temp;
			}
			num[0]-=max*maybe[i][0];
			num[1]-=max*maybe[i][1];
			num[2]-=max*maybe[i][2];
			count+=max;
		}
		printf("Case %d: %d\n",++c,count);
	}
}
