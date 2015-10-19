////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-01 19:12:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3651
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

struct step{
	int left,right;
};

int Abs(const int& a){
	int temp=(a>>31);
	return (a+temp)^temp;
}
int Max(const int& a,const int& b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}
int Min(const int& a,const int& b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

int dp[110][11][11];
void move(step start,step end,int step,bool lr){
	int left=Abs(start.left-end.left);
	int right=Abs(start.right-end.right);
	if(lr) left++;
	else right++;
	int tmp=Max(left,right);
	if(dp[step+1][end.left][end.right]==-1||dp[step+1][end.left][end.right]>=dp[step][start.left][start.right]+tmp){
		dp[step+1][end.left][end.right]=dp[step][start.left][start.right]+tmp;
	}
}

int main(){
	char str[110];
	while(scanf("%s",str)!=EOF){
		memset(dp,-1,sizeof(dp));
		int len=strlen(str);
		int tag=str[0]-'0';
		if(tag==0) tag=10;
		step start,end;
		dp[0][5][6]=0;
		start.left=5;start.right=6;
		for(int i=1;i<=10;i++){
			if(i<tag){
				end.left=i;
				end.right=tag;
				move(start,end,0,0);
			}else if(i>tag){
				end.left=tag;
				end.right=i;
				move(start,end,0,1);
			}else continue;
		}
		for(int i=1;i<len;i++){
			int ntag=str[i]-'0';
			if(ntag==0) ntag=10;
			for(int j=1;j<=10;j++){
				if(j<tag){
					start.left=j;
					start.right=tag;
					for(int k=1;k<=10;k++){
						if(k<ntag){
							end.left=k;
							end.right=ntag;
							move(start,end,i,0);
						}else if(k>ntag){
							end.left=ntag;
							end.right=k;
							move(start,end,i,1);
						}
					}
				}else if(j>tag){
					start.left=tag;
					start.right=j;
					for(int k=1;k<=10;k++){
						if(k<ntag){
							end.left=k;
							end.right=ntag;
							move(start,end,i,0);
						}else if(k>ntag){
							end.left=ntag;
							end.right=k;
							move(start,end,i,1);
						}
					}
				}else continue;
			}
			tag=ntag;
		}
//		for(int i=0;i<len;i++){
//			tag=str[i]-'0';
//			if(tag==0) tag=10;
//			for(int j=1;j<=10;j++){
//				if(j<tag){
//					end.left=j;
//					end.right=tag;
//					printf("%d ",dp[i+1][end.left][end.right]);
//				}else if(j>tag){
//					end.left=tag;
//					end.right=j;
//					printf("%d ",dp[i+1][end.left][end.right]);
//				}else printf("- ");
//			}
//			puts("");
//		}
		int min=1000000;
		for(int i=1;i<=10;i++){
			if(i<tag){
				end.left=i;
				end.right=tag;
				min=Min(min,dp[len][end.left][end.right]);
			}else if(i>tag){
				end.left=tag;
				end.right=i;
				move(start,end,0,1);
				min=Min(min,dp[len][end.left][end.right]);
			}else continue;
		}
		printf("%d\n",min);
	}
}
