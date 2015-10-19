////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-21 13:13:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Lowbit(x) (x&(x^(x-1)))

int index[50010],n;
int Sum(int t)
{
	int sum=0;
	while(t>0){
		sum+=index[t];
		t-=Lowbit(t);
	}
	return sum;
}

void Add(int pos,int num)
{
	while(pos<=n){
		index[pos]+=num;
		pos+=Lowbit(pos);
	}
}

int main(){
	int t,c=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(index,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++){
			int temp;
			scanf("%d",&temp);
			Add(i,temp);
		}
		char cmd[10];
		printf("Case %d:\n",++c);
		while(scanf("%s",cmd),strcmp(cmd,"End")){
			if(strcmp(cmd,"Query")==0){
				int s,e;
				scanf("%d%d",&s,&e);
				printf("%d\n",Sum(e)-Sum(s-1));
			}else if(strcmp(cmd,"Add")==0){
				int pos,num;
				scanf("%d%d",&pos,&num);
				Add(pos,num);
			}else if(strcmp(cmd,"Sub")==0){
				int pos,num;
				scanf("%d%d",&pos,&num);
				Add(pos,-num);
			}
		}
	}

}