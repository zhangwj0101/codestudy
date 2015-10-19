////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-13 14:00:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3531
////Problem Title: 
////Run result: Accept
////Run time:656MS
////Run memory:10156KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int maze[1010][1010];
int sum[1010][1010];
int maze2[510][510];
int sum2[510][510];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&maze[i][j]);
				sum[i][j]=sum[i][j-1]+maze[i][j];
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&maze2[i][j]);
				sum2[i][j]=sum2[i][j-1]+maze2[i][j];
			}
		}
		//if(m>n) goto no;
		for(int ii=1;ii<=n-m+1;ii++){
			for(int jj=1;jj<=n-m+1;jj++){
				for(int k=m;k>0;k--){
					for(int l=m;l>0;l--){
						if(sum[ii+l-1][jj+k-1]-sum[ii-1][jj-1]!=sum2[l][k]){
							goto loop;
						}
					}
				}
				//if(maze[ii][jj]!=maze2[1][1]||
				//	maze[ii+m-1][jj+m-1]!=maze2[m][m]||
				//	maze[ii][jj+m-1]!=maze2[1][m]||
				//	maze[ii+m-1][jj]!=maze2[m][1]){
				//		continue;
				//}

				goto yes;
loop: ;
			}
		}
no:
		printf("No\n");
		continue;
yes: ;
		printf("Yes\n");
		continue;
	}
}