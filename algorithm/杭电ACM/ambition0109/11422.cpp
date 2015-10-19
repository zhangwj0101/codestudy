////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-19 12:20:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1142
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:608KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;
const int MAX_SIZE=1000;
const int INF=2147483647;

struct City
{
    int LCity;
    int Cost;
};
vector<City> Graph[MAX_SIZE+1];
int Path[MAX_SIZE+1];
bool Hush[MAX_SIZE+1];
int dfs[MAX_SIZE+1];
int n,m;

inline bool scan_ud(int &num)
{
	char in;
	in=getchar();
	if(in==EOF) return false;
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	return true;
}
void Dijkstra(int START,int END)
{
    memset(Hush,true,sizeof(Hush));
    for(int i=1;i<=n;i++) Path[i]=INF;
    int Ups;
    Ups=START;
    Path[Ups]=0;
    Hush[Ups]=false;
    while(Ups!=END)
    {
        for(unsigned i=0;i<Graph[Ups].size();i++)
            if(Graph[Ups][i].Cost+Path[Ups]<Path[Graph[Ups][i].LCity])
                Path[Graph[Ups][i].LCity]=Graph[Ups][i].Cost+Path[Ups];
        int Min=INF;
        for(int i=1;i<=n;i++)
            if(Path[i]<Min&&Hush[i])
            {
                Min=Path[i];
                Ups=i;
            }
        if(Min==INF) return;
        Hush[Ups]=false;
    }
}

int Dfs(int tt)
{
    int count=0;
    for(unsigned i=0;i<Graph[tt].size();i++)
    {
        if(Path[tt]>Path[Graph[tt][i].LCity])
        {
            if(dfs[Graph[tt][i].LCity]==-1)
                dfs[Graph[tt][i].LCity]=Dfs(Graph[tt][i].LCity);
            count+=dfs[Graph[tt][i].LCity];
        }
    }
    return count;
}

int main()
{
    while(scan_ud(n),n)
    {
        scan_ud(m);
        for(int i=1;i<=n;i++)
            Graph[i].clear();
        for(int i=0,c1,c2,cost;i<m;i++)
        {
            City tcity;
            scan_ud(c1);scan_ud(c2);scan_ud(cost);
            tcity.LCity=c2;tcity.Cost=cost;
            Graph[c1].push_back(tcity);
            tcity.LCity=c1;tcity.Cost=cost;
            Graph[c2].push_back(tcity);
        }
        Dijkstra(2,1);
        memset(dfs,-1,sizeof(dfs));
        dfs[2]=1;
        cout<<Dfs(1)<<endl;
    }
    return 0;
}