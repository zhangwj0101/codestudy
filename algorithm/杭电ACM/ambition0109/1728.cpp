////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-26 14:25:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1728
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:1732KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
using namespace std;
int tmp,i,j,n,m;
bool tr[102][102];//标记是否可以访问或已经访问过
int dr[4][2]={0,1,0,-1,-1,0,1,0};//控制方向
struct Point
{
    int x,y,s;//s用来标记到当前点的拐弯数目
}point[2];
void bfs()
{
    queue<Point> Q;
    Point p,q;
    point[0].s=-1;
    Q.push(point[0]);
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        tr[p.y][p.x]=0;//做已访问标记
        for(i=0;i<4;i++)//向四个方向搜索
        {
            q.x=p.x+dr[i][0];
            q.y=p.y+dr[i][1];
            while(q.x>0&&q.y<=n&&q.x<=m&&q.y>0)
            {
                if(!tr[q.y][q.x])//如果已经访问过则退出
                    break;
                q.s=p.s+1;
                if(q.x==point[1].x&&q.y==point[1].y&&q.s<=tmp)//判断是否已经走到目的地,到达则输出结果,返回
                {
                    cout<<"yes"<<endl;
                    return;
                }
                if(q.s<=tmp)//未搜到目的地而且满足搜索条件则进栈
                    Q.push(q);
                q.x=q.x+dr[i][0];//继续下一个搜索
                q.y=q.y+dr[i][1];
            }
        }
    }
    cout<<"no"<<endl;
}
int main()
{
    int t;
    char b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                cin>>b;
                if(b=='.')
                    tr[i][j]=1;
                else
                    tr[i][j]=0;
            }
        cin>>tmp>>point[0].x>>point[0].y>>point[1].x>>point[1].y;
        if(point[0].x==point[1].x&&point[0].y==point[1].y)
            cout<<"yes"<<endl;
        else
            bfs();
    }
    return 0;
}