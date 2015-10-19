////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-02 09:58:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1385
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:460KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

const int MAX_PATH=1000;
const int INF=2000000000;
int Point[MAX_PATH+1][MAX_PATH+1],Path[MAX_PATH+1];
int Pre[MAX_PATH+1];
bool Hush[MAX_PATH+1];
int city[MAX_PATH+1];
int n,m;

int Dijkstra(int START,int END)
{
	for(int i=1;i<=n;i++)
	{
		Path[i]=INF;
		Hush[i]=true;
		Pre[i]=0;
	}
	int Ups;
	Ups=START;
	Path[Ups]=0;
	Hush[Ups]=false;
	while(Ups!=END)		//Dijkstra
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=Ups)
			if(Point[Ups][i]!=-1)
			{
				if(Path[Ups]+Point[Ups][i]+city[i]<Path[i])
				{
					Path[i]=Path[Ups]+Point[Ups][i]+city[i];
					Pre[i]=Ups;
				}else if(Path[Ups]+Point[Ups][i]+city[i]==Path[i])
					if(Pre[i]>Ups) Pre[i]=Ups;
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
		if(Min==INF) return INF;
		Hush[Ups]=false;
	}
	return Path[END];
}

void main()
{
    while(cin>>n,n)
    {
        for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>Point[j][i];
		for(int i=1;i<=n;i++)
			cin>>city[i];
		int c1,c2;
		while(cin>>c1>>c2,(c1+1)||(c2+1))
		{
			int tt;
			tt=Dijkstra(c2,c1)-city[c1];
			cout<<"From "<<c1<<" to "<<c2<<" :"<<endl;
			cout<<"Path: ";
			if(c1==c2){
				cout<<c1<<endl;
				cout<<"Total cost : "<<0<<endl;
				cout<<endl;
				continue;
			}
			int p=c1;
			while(p!=c2&&p)
			{
				cout<<p<<"-->";
				p=Pre[p];
			}
			cout<<c2<<endl;
			cout<<"Total cost : "<<tt<<endl;
			cout<<endl;
		}
    }
}