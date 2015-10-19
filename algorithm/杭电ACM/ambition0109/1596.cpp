////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-28 13:11:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1596
////Problem Title: 
////Run result: Accept
////Run time:1484MS
////Run memory:6732KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;

const int MAX_PATH=1000;
const double INF=2147483647.;
double Point[MAX_PATH+1][MAX_PATH+1],Path[MAX_PATH+1];
bool Hash[MAX_PATH+1];
int START,END;

void main()
{
    int n,m;
    while(cin>>n)
    {
		for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
				double t;
				cin>>t;
				if(t)
					Point[i][j]=-log10(t);
				else
					Point[i][j]=INF;
			}
		for(cin>>m;m>0;m--)
		{
			cin>>START>>END;
			for(int i=1;i<=n;i++)
			{
				Path[i]=INF;
				Hash[i]=true;
			}
			int Ups,Is=1;
			{
				Ups=START;
				Path[Ups]=0;
				Hash[Ups]=false;
			}
			while(Ups!=END)
			{
				for(int i=1;i<=n;i++)
				{
					if(Point[Ups][i])
						if(Path[Ups]+Point[Ups][i]<Path[i])
							Path[i]=Path[Ups]+Point[Ups][i];
				}
				double Min=INF;
				for(int i=1;i<=n;i++)
				{
					if(Path[i]<Min&&Hash[i])
					{
						Min=Path[i];
						Ups=i;
					}
				}
				if(Min==INF) {Is=0;break;}
				Hash[Ups]=false;
			}
			if(Is)
				printf("%.3lf\n",pow(10.,-Path[END]));
			else
				cout<<"What a pity!"<<endl;
		}
    }
}