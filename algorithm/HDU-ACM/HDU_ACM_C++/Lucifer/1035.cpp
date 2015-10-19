////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-08-02 20:21:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
char Maze[11][11];
int visited[11][11];
int row,col;
struct Point{int x,y;}P[101],now;
int count;
int travel()
{
	if(now.x<0||now.y<0||now.x>=col||now.y>=row)
		return 1;
	if(visited[now.y][now.x])
		return 0;
	else
		visited[now.y][now.x]=1;
	P[count++]=now;
	switch(Maze[now.y][now.x])
	{
	case 'E':
		now.x++;
		break;
	case 'S':
		now.y++;
		break;
	case 'W':
		now.x--;
		break;
	case 'N':
		now.y--;
		break;
	}
	return travel();
}
void clear()
{
	int i;
	for(i=0;i<count;i++)
		visited[P[i].y][P[i].x]=0;
}
int main()
{
	int i,start;
	while(cin>>row&&row)
	{
		cin>>col>>start;
		count=0;
		for(i=0;i<row;i++)scanf("%s",Maze[i]);
		now.x=start-1,now.y=0;
		if(travel())
			printf("%d step(s) to exit\n",count);
		else
		{
			for(i=0;i<count;i++)
				if(P[i].x==now.x&&P[i].y==now.y)
					break;
			printf("%d step(s) before a loop of %d step(s)\n",i,count-i);
		}
		clear();
	}
   return 0;
}