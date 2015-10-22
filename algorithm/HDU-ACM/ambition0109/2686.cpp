////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-14 11:28:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2686
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:472KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int map[31][31],value[60][31][31];
void main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>map[i][j];
		memset(value,0,sizeof(value));
		value[2][1][2]=map[1][1]+map[2][1]+map[1][2];
		for(int i=2;i<n;i++){
			for(int j=1;j<=i;j++){
				for(int k=j+1;k<=i;k++){
					if(value[i][j][k]+map[j][i-j+2]+map[k][i-k+2]>value[i+1][j][k])value[i+1][j][k]=value[i][j][k]+map[j][i-j+2]+map[k][i-k+2];
					if(value[i][j][k]+map[j][i-j+2]+map[k+1][i-k+1]>value[i+1][j][k+1])value[i+1][j][k+1]=value[i][j][k]+map[j][i-j+2]+map[k+1][i-k+1];
					if(value[i][j][k]+map[j+1][i-j+1]+map[k+1][i-k+1]>value[i+1][j+1][k+1])value[i+1][j+1][k+1]=value[i][j][k]+map[j+1][i-j+1]+map[k+1][i-k+1];
					if(j!=k-1)
						if(value[i][j][k]+map[j+1][i-j+1]+map[k][i-k+2]>value[i+1][j+1][k])value[i+1][j+1][k]=value[i][j][k]+map[j+1][i-j+1]+map[k][i-k+2];
				}
			}
		}
		for(int i=n+1;i<=2*n-2;i++){
			for(int j=i-n+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					int max=value[i-1][j][k];
					if(value[i-1][j-1][k-1]>max) max=value[i-1][j-1][k-1];
					if(value[i-1][j-1][k]>max) max=value[i-1][j-1][k];
					if(j!=k-1)
						if(value[i-1][j][k-1]>max) max=value[i-1][j][k-1];
					value[i][j][k]=max+map[j][i-j+1]+map[k][i-k+1];
				}
			}
		}
		cout<<value[2*n-2][n-1][n]+map[n][n]<<endl;
	}
}