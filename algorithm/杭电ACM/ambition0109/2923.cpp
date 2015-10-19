////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-02 13:15:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2923
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

const int MAX_SIZE=150;
const int INF=2147483647;
int Path[MAX_SIZE+1][MAX_SIZE+1];
string noc[MAX_SIZE+1];
int car[1050];

void main()
{
	int n,m,mm,t,tt=0;
	while(cin>>n>>m>>t,n||m||t)
	{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) Path[i][j]=0;
				else Path[i][j]=INF;
			}
		}
		cin>>noc[1];mm=1;
		string tn;int tcc;
		for(int i=0;i<m;i++)
		{
			cin>>tn;
			tcc=0;
			for(int j=1;j<=mm;j++)
				if(noc[j]==tn){tcc=j;break;}
			if(tcc==0) {tcc=++mm;noc[tcc]=tn;}
			car[i]=tcc;
		}
		for(int i=0;i<t;i++)
		{
			string tc,c1,c2;
			int cc1,cc2,cost;
			cin>>c1>>tc>>c2;
			cc1=0;
			for(int j=1;j<=mm;j++)
				if(noc[j]==c1){cc1=j;break;}
			if(cc1==0) {cc1=mm++;noc[mm]=c1;}
			cc2=0;
			for(int j=0;j<=mm;j++)
				if(noc[j]==c2){cc2=j;break;}
			if(cc2==0) {cc2=mm++;noc[mm]=c2;}
			cost=tc[2]-'0';
			int k=3;
			while(tc[k]!='-'){
				cost*=10;
				cost+=tc[k]-'0';
				k++;
			}
			if(tc[0]=='<'&&Path[cc2][cc1]>cost) Path[cc2][cc1]=cost;
			if(tc[tc.length()-1]=='>'&&Path[cc1][cc2]>cost)
				Path[cc1][cc2]=cost;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(Path[i][k]==INF||Path[k][j]==INF) continue;
					if(Path[i][j]>Path[i][k]+Path[k][j])
						Path[i][j]=Path[i][k]+Path[k][j];
				}
			}
		}
		int sum=0;
		for(int i=0;i<m;i++)
			sum+=Path[1][car[i]]+Path[car[i]][1];
		cout<<++tt<<". "<<sum<<endl;
	}
}