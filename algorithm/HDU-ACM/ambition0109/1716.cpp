////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-13 14:12:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1716
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int Hash[10];
int num; bool flag,cflag=false;
void Dfs(int t){
	if(t==4){
		if(flag) printf(" ");
		else if(cflag) printf("\n");
		cflag=true;
		flag=true;
		printf("%d",num);
		return;
	}
	for(int i=0;i<10;i++){
		if(Hash[i]){
			if(t==0&&i==0) continue;
			Hash[i]--;
			num*=10; num+=i;
			Dfs(t+1);
			num/=10;
			Hash[i]++;
		}
		if(t==0) flag=false;
	}

}

int main(){
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d),a||b||c||d){
		memset(Hash,0,sizeof(Hash));
		Hash[a]++; Hash[b]++;
		Hash[c]++; Hash[d]++;
		Dfs(0);
		puts("");
	}
}