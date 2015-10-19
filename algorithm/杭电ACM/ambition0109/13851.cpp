////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-19 12:14:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1385
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:372KB
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

inline bool scan_d(int &num)
{
	char in;bool PN=false;
	in=getchar();
	if(in==EOF) return false;
	while(in!='-'&&(in<'0'||in>'9')) in=getchar();
	if(in=='-'){ PN=true;num=0;}
	else num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	if(PN) num=-num;
	return true;
}

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
    while(Ups!=END)        //Dijkstra
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
    while(scan_d(n),n)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scan_d(Point[j][i]);
        for(int i=1;i<=n;i++)
            scan_d(city[i]);
        int c1,c2;
        while(scan_d(c1),scan_d(c2),(c1+1)||(c2+1))
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