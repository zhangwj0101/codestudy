////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-04 12:33:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1690
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:496KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;
const int MAX_SIZE=150;
const __int64 INF=9223372036854775807LL;

struct City{
	int LCity;
	__int64 Cost;
};
vector<City> Graph[MAX_SIZE+1];
__int64 Path[MAX_SIZE+1];
__int64 num[MAX_SIZE+1];
bool Hush[MAX_SIZE+1];
int n,m;

__int64 Dijkstra(int START,int END)
{
	for(int i=1;i<=n;i++){
		Path[i]=INF;
		Hush[i]=true;
	}
	int Ups=START;
	Path[Ups]=0;
	Hush[Ups]=false;
	while(Ups!=END)
	{
		for(unsigned i=0;i<Graph[Ups].size();i++)
			if(Graph[Ups][i].Cost+Path[Ups]<Path[Graph[Ups][i].LCity])
				Path[Graph[Ups][i].LCity]=Graph[Ups][i].Cost+Path[Ups];
		__int64 Min=INF;
		for(int i=1;i<=n;i++){
			if(Path[i]<Min&&Hush[i]){
				Min=Path[i];Ups=i;
			}
		}
		if(Min==INF) return -1;
		Hush[Ups]=false;
	}
	return Path[END];
}

void main()
{
	__int64 t,Case;cin>>t;
	for(Case=1;Case<=t;Case++)
	{
		__int64 l[4],c[4];
		cin>>l[0]>>l[1]>>l[2]>>l[3];
		cin>>c[0]>>c[1]>>c[2]>>c[3];
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>num[i];
			Graph[i].clear();
		}
		for(int i=1;i<=n;i++){
			City tcity;
			for(int j=i+1;j<=n;j++){
				__int64 temp=(num[i]-num[j])>0?(num[i]-num[j]):(num[j]-num[i]);
				if(temp<=l[0]){
					tcity.Cost=c[0];
					tcity.LCity=j;Graph[i].push_back(tcity);
					tcity.LCity=i;Graph[j].push_back(tcity);
				}else if(temp<=l[1]){
					tcity.Cost=c[1];
					tcity.LCity=j;Graph[i].push_back(tcity);
					tcity.LCity=i;Graph[j].push_back(tcity);
				}else if(temp<=l[2]){
					tcity.Cost=c[2];
					tcity.LCity=j;Graph[i].push_back(tcity);
					tcity.LCity=i;Graph[j].push_back(tcity);
				}else if(temp<=l[3]){
					tcity.Cost=c[3];
					tcity.LCity=j;Graph[i].push_back(tcity);
					tcity.LCity=i;Graph[j].push_back(tcity);
				}
			}
		}
		cout<<"Case "<<Case<<':'<<endl;
		for(int i=0;i<m;i++){
			int c1,c2;cin>>c1>>c2;
			if(c1==c2){
				cout<<"The minimum cost between station "<<c1<<" and station "<<c2<<" is "<<0<<"."<<endl;
				continue;
			}
			__int64 temp=Dijkstra(c1,c2);
			if(temp==-1) cout<<"Station "<<c1<<" and station "<<c2<<" are not attainable."<<endl;
			else cout<<"The minimum cost between station "<<c1<<" and station "<<c2<<" is "<<temp<<"."<<endl;
		}
	}
}