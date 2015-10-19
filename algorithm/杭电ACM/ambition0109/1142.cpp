////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-01 15:20:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1142
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:4232KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int n;//ʮ��·����
int map[1001][1001];
int dist[1001],dp[1001];
int s[1001];
void dijkstra(int v)//�Ͻ�˹�����㷨
{
    int i,j,mins,index;

    for(i=1;i<=n;i++)
    {
        dist[i] = map[i][v];
        s[i] = 0;
    }
    dist[v] = 0;
    s[v] = 1;
    for(i=1;i<n;i++)
    {
        mins = 2000000;
        for(j=1;j<=n;j++)
        {
            if(s[j]==0 && dist[j]<mins)
            {
                mins = dist[j];
                index = j;
            }
        }
        if(mins == 2000000)//ע�� ��û�� �����м����
          break;
        s[index] = 1;
        for(j=1;j<=n;j++)
        {
            if(s[j]==0 && dist[j]>dist[index]+map[j][index])
                dist[j] = dist[index]+map[j][index];
        }
    }
}

int dfs(int v)//���䷨����
{
    if(dp[v] != -1)
        return dp[v];
    if(v == 2)
        return 1;
    int i,temp,sum=0;
    for(i=1;i<=n;i++)
    {
        if(map[v][i]!=2000000 && dist[v] > dist[i])//��·��ͨ����Ҫȥ��i�㵽�յ�վ�ľ���Ҫ��v���յ�վ�ľ���С
        {
            temp = dfs(i);
            sum += temp;
        }
    }
    dp[v] = sum;
    return sum;
}

int main()
{
    while(cin>>n && n)
    {
        int i,j,d,m;
        cin>>m;
        for(i=1;i<=n;i++)
        {
            dp[i] = -1;
            for(j=1;j<=n;j++)
                map[i][j] = 2000000;
        }
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&d);
            map[i][j] = map[j][i] = d;//����ͼ
        }
        //������㵽�յ�վ����̾���
        dijkstra(2);//2Ϊ�յ�վ
        dfs(1);//��1����
        cout<<dp[1]<<endl;
    }
    return 0;
}
