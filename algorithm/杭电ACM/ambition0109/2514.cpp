////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-29 19:28:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2514
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*
 * 2514.cpp
 *
 *  Created on: 2010-12-29
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define ABS(x) (x>0?x:(-x))

//bool vis[10];
//int ans[10],cnt;
//void dfs(int step){
//	if(step==8){
//		if(ABS((ans[0]-ans[1]))==1) return;
//		if(ABS((ans[0]-ans[2]))==1) return;
//		if(ABS((ans[0]-ans[3]))==1) return;
//		if(ABS((ans[1]-ans[2]))==1) return;
//		if(ABS((ans[1]-ans[4]))==1) return;
//		if(ABS((ans[1]-ans[5]))==1) return;
//		if(ABS((ans[2]-ans[3]))==1) return;
//		if(ABS((ans[2]-ans[4]))==1) return;
//		if(ABS((ans[2]-ans[5]))==1) return;
//		if(ABS((ans[2]-ans[6]))==1) return;
//		if(ABS((ans[3]-ans[5]))==1) return;
//		if(ABS((ans[3]-ans[6]))==1) return;
//		if(ABS((ans[4]-ans[5]))==1) return;
//		if(ABS((ans[4]-ans[7]))==1) return;
//		if(ABS((ans[5]-ans[6]))==1) return;
//		if(ABS((ans[5]-ans[7]))==1) return;
//		if(ABS((ans[6]-ans[7]))==1) return;
//		for(int i=0;i<8;i++){
//			printf("%d ",ans[i]);
//		}
//		puts("");
//		cnt++;
//		return;
//	}
//	for(int i=1;i<=8;i++){
//		if(vis[i]) continue;
//		vis[i]=true;
//		ans[step]=i;
//		dfs(step+1);
//		vis[i]=false;
//	}
//}

inline char in(){
	int ch;
	do{
		ch=getchar();
	}while(ch<'0'||ch>'9');
	return ch;
}

char ans[4][10]={"25863147","26854137","73145862","74136852"};
char nn[10];
int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<8;i++){
			nn[i]=in();
		}
		int cnt=0,v;
		for(int k=0,i;k<4;k++){
			for(i=0;i<8;i++){
				if(nn[i]=='0') continue;
				if(ans[k][i]!=nn[i]){
					break;
				}
			}
			if(i==8){
				v=k;
				cnt++;
				if(cnt>1) break;
			}
		}
		printf("Case %d:",++cas);
		if(cnt>1){
			puts(" Not unique");
		}else if(cnt==1){
			for(int i=0;i<8;i++){
				printf(" %c",ans[v][i]);
			}
			puts("");
		}else if(cnt==0){
			puts(" No answer");
		}

	}
}
