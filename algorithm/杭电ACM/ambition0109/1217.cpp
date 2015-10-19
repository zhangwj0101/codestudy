////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-01 08:52:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1217
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const int MAX_SIZE=30;
const int INF=2147483647;

double map[MAX_SIZE+1][MAX_SIZE+1];
string city[MAX_SIZE+1];
void main()
{
	int n,m,t=0;
	while(cin>>n,n)
	{
		for(int i=1;i<=n;i++)
			cin>>city[i];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			{
				map[i][j]=0;
			}
		cin>>m;
		for(int i=0;i<m;i++)
		{
			string c1,c2;
			int cc1,cc2;
			double cost;
			cin>>c1>>cost>>c2;
			cc1=0;
			while(city[cc1]!=c1) cc1++;
			cc2=0;
			while(city[cc2]!=c2) cc2++;
			map[cc1][cc2]=cost;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(map[i][j]<map[i][k]*map[k][j])
						map[i][j]=map[i][k]*map[k][j];
				}
			}
		}
		bool is=false;
		for(int i=1;i<=n;i++)
			if(map[i][i]>1)
			{is=true;break;}
		if(is) cout<<"Case "<<++t<<": Yes"<<endl;
		else cout<<"Case "<<++t<<": No"<<endl;
	}
}