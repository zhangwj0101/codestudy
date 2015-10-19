////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-03 10:19:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2962
////Problem Title: 
////Run result: Accept
////Run time:718MS
////Run memory:684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;
const int MAX_SIZE=1000;
const int INF=2147483647;

struct City
{
	int LCity;
	int Hight;
	int Cost;
};
vector<City> Graph[MAX_SIZE+1];
int Path[MAX_SIZE+1];
bool Hush[MAX_SIZE+1];
int n,m;

int Dijkstra(int START,int END,int MAXHight)
{
	for(int i=1;i<=n;i++)
	{
		Path[i]=INF;
		Hush[i]=true;
	}
	int Ups=START;
	Path[Ups]=0;
	Hush[Ups]=false;
	while(Ups!=END)
	{
		for(unsigned i=0;i<Graph[Ups].size();i++)
		{
			if(Graph[Ups][i].Hight>=MAXHight)
			if(Graph[Ups][i].Cost+Path[Ups]<Path[Graph[Ups][i].LCity])
				Path[Graph[Ups][i].LCity]=Graph[Ups][i].Cost+Path[Ups];
		}
		int Min=INF;
		for(int i=1;i<=n;i++)
		{
			if(Path[i]<Min&&Hush[i])
			{
				Min=Path[i];
				Ups=i;
			}
		}
		if(Min==INF) return -1;
		Hush[Ups]=false;
	}
	return Path[END];
}
void main()
{
	int Case=0;
	while(cin>>n>>m,n||m)
	{
		for(int i=1;i<=n;i++)
			Graph[i].clear();
		for(int i=0,c1,c2,cost;i<m;i++)
		{
			City tcity;int H;
			cin>>c1>>c2>>H>>cost;
			tcity.Hight=H;
			if(tcity.Hight==-1)
				tcity.Hight=INF;
			tcity.Cost=cost;
			tcity.LCity=c2;
			Graph[c1].push_back(tcity);
			tcity.LCity=c1;
			Graph[c2].push_back(tcity);
		}
		int c1,c2,MH;
		cin>>c1>>c2>>MH;
		int top=MH,bottom=0,Mid,len=-1,ans;
		while(top>=bottom){
			Mid=(top+bottom)/2;
			int temp=Dijkstra(c1,c2,Mid);
			if(temp!=-1){
				ans=Mid;
				len=temp;
				bottom=Mid+1;
			}else{
				top=Mid-1;
			}
		}
		if(Case) cout<<endl;
		cout<<"Case "<<++Case<<':'<<endl;
		if(len==-1){
			cout<<"cannot reach destination"<<endl;
			continue;
		}
		cout<<"maximum height = "<<ans<<endl;
		cout<<"length of shortest route = "<<len<<endl;
	}
}