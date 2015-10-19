////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-14 12:50:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2680
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:4192KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

const int MAX_PATH=1000;
const int INF=2147483647;
int Point[MAX_PATH+1][MAX_PATH+1],Path[MAX_PATH+1];
bool Hush[MAX_PATH+1];
int START[MAX_PATH+1],END;

void main()
{
    int n,m;
    while(cin>>n>>m>>END)
    {
		for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                Point[i][j]=0;
        for(int i=0,cost,p1,p2;i<m;i++)
        {
            cin>>p1>>p2>>cost;
			if(!Point[p1][p2]||(Point[p1][p2]&&Point[p1][p2]>cost))
				Point[p1][p2]=cost;
        }
        for(int i=1;i<=n;i++)
        {
            Path[i]=INF;
            Hush[i]=true;
        }
		int t;
		cin>>t;
		for(int i=0;i<t;i++)
		{
			cin>>START[i];
			Path[START[i]]=0;
		}
		int Ups,Is=1;
		Ups=START[0];
		Hush[START[0]]=false;
        while(Ups!=END)		//Dijkstra
        {
            for(int i=1;i<=n;i++)
            {
                if(Point[Ups][i])
                if(Path[Ups]+Point[Ups][i]<Path[i])
				{
					Path[i]=Path[Ups]+Point[Ups][i];
				}
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
			if(Min==INF) {Is=0;break;}
            Hush[Ups]=false;
        }
		if(Is)
			cout<<Path[END]<<endl;
		else
			cout<<"-1"<<endl;
    }
}