////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-29 08:28:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2112
////Problem Title: 
////Run result: Accept
////Run time:2796MS
////Run memory:396KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

const int INF=2147483647;
int cross[151][151],sstr[151];
string city[151];
bool hush[151];

void main()
{
    int m,t;
    while(cin>>m,m+1)
    {
        cin>>city[1]>>city[2];t=3;
		memset(cross,0,sizeof(cross));
        string c1,c2;
        int cc1,cc2,time;
        for(int i=0;i<m;i++)
        {
            cin>>c1>>c2>>time;
            int j;
            for(j=1;j<t;j++)
            {if(c1==city[j]){ cc1=j;break;}}
            if(j==t) {city[t]=c1;cc1=t;t++;}
            for(j=1;j<t;j++)
            {if(c2==city[j]){ cc2=j;break;}}
            if(j==t) {city[t]=c2;cc2=t;t++;}
            if(!cross[cc1][cc2]||(cross[cc1][cc2]&&cross[cc1][cc2]>time))
                cross[cc1][cc2]=time;
			if(!cross[cc2][cc1]||(cross[cc2][cc1]&&cross[cc2][cc1]>time))
                cross[cc2][cc1]=time;
        }
		if(city[1]==city[2]){
			cout<<"0"<<endl;
			continue;
		}
        for(int i=1;i<t;i++)
        {
            sstr[i]=INF;
            hush[i]=false;
        }
        sstr[1]=0;hush[1]=true;
        int ups=1,is=1;
        while(ups!=2)
        {
            for(int i=1;i<t;i++)
            {
                if(cross[ups][i])
                if(sstr[ups]+cross[ups][i]<sstr[i])
                    sstr[i]=sstr[ups]+cross[ups][i];
            }
            int min=INF;
            for(int i=2;i<t;i++)
            {
                if(sstr[i]<min&&!hush[i])
                {min=sstr[i];ups=i;}
            }
            if(min==INF) {is=0;break;}
            hush[ups]=true;
        }
        if(is) cout<<sstr[2]<<endl;
        else cout<<"-1"<<endl;
    }
}