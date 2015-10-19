////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-09 13:14:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1027
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

bool num[1005];
int frac[11];
int main(){
	frac[0]=1;
	for(int i=1;i<10;i++){
		frac[i]=frac[i-1]*i;
	}
	
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int v=1; m-=1;
		while(frac[v]<=m) v++;
		
		bool flag=false;
		memset(num,true,sizeof(num));
		for(int i=1;i<=n-v;i++){
			if(flag) printf(" ");
			flag=true;
			printf("%d",i);
			num[i]=false;
		}

		for(int i=v-1;i>=0;i--){
			int t=m/frac[i],k=1;
			for(int j=0;j<t;j++,k++){
				while(!num[k]) k++;
			}
			while(!num[k]) k++;
			num[k]=false;
			if(flag) printf(" ");
			flag=true;
			printf("%d",k);
			m=m%frac[i];
		}
		puts("");
	}
}