////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-30 09:11:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1596
////Problem Title: 
////Run result: Accept
////Run time:4046MS
////Run memory:6716KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;

const int MAX_SIZE=1000;
const int INF=2147483647;
double Path[MAX_SIZE+1][MAX_SIZE+1];

void main()
{
	int n,m;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				double temp; cin>>temp;
				if(temp) Path[i][j]=-log10(temp);
				else Path[i][j]=INF;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(Path[i][j]>Path[i][k]+Path[k][j])
						Path[i][j]=Path[i][k]+Path[k][j];
				}
			}
		}
		for(cin>>m;m>0;m--)
		{
			int c1,c2;
			cin>>c1>>c2;
			if(Path[c1][c2]==INF)
				printf("What a pity!\n");
			else
				printf("%.3lf\n",pow(10.,-Path[c1][c2]));
		}
	}
}
