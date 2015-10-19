////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-13 20:14:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const int INF=10000000;
int cross[201][201],sstr[201];
bool hush[201];
void main()
{
    int n,m,t;
    while(cin>>n>>m)
    {
		t=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cross[i][j]=0;
        int c1,c2,time;
        for(int i=0;i<m;i++)
        {
            cin>>c1>>c2>>time;
			if(!cross[c1][c2]||(cross[c1][c2]&&cross[c1][c2]>time))
			{
				cross[c1][c2]=time;
				cross[c2][c1]=time;
			}
        }
        for(int i=0;i<n;i++)
        {
            sstr[i]=INF;
            hush[i]=false;
        }
		cin>>c1>>c2;
		sstr[c1]=0;hush[c1]=true;
        int ups=c1;
        while(ups!=c2)
        {
            for(int i=0;i<n;i++)
            {
                if(cross[ups][i])
                if(sstr[ups]+cross[ups][i]<sstr[i])
                    sstr[i]=sstr[ups]+cross[ups][i];
            }
			int min=INF;
            for(int i=0;i<n;i++)
            {
                if(sstr[i]<min&&!hush[i])
                {min=sstr[i];ups=i;}
            }
			if(min==INF)
			{t=0;break;}
            hush[ups]=true;
        }
		if(t) cout<<sstr[c2]<<endl;
		else cout<<"-1"<<endl;
    }
}