////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-09 12:28:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1361
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

bool s[45];
int Ans[25];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(s,false,sizeof(s));
		for(int i=0;i<n;i++){
			int p;
			scanf("%d",&p);
			s[p+i]=true;
		}
		stack<int> sta;
		for(int i=0,j=0;i<n*2;i++){
			if(s[i]){
				int e=sta.top();
				sta.pop();
				Ans[j++]=(i-e+1)>>1;
			}else{
				sta.push(i);
			}
		}
		printf("%d",Ans[0]);
		for(int i=1;i<n;i++){
			printf(" %d",Ans[i]);
		}
		puts("");
	}
}