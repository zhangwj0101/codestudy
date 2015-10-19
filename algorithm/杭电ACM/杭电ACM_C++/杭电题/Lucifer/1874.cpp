////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-10 23:34:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:364KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include<math.h>
#define inf 1000000000
int main()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int map[201][201],v[201],min[201],j,k;
		int x,y,weight,s,t;
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(j==i) map[i][j]=0;
				else map[i][j]=map[j][i]=inf;
				
				for(i=0;i<m;i++)
				{
					scanf("%d%d%d",&x,&y,&weight);
					//map[x][y]=map[x][y]=weight;
					if(weight<map[x][y]) map[x][y]=map[y][x]=weight;
				}
				scanf("%d%d",&s,&t);
				
				for(i=0;i<n;i++)
					min[i]=inf,v[i]=0;//,pre[i]=-1;
				
				for(min[s]=0,j=0;j<n;j++)
				{
					for(k=-1,i=0;i<n;i++)
						if(!v[i]&&(k==-1||min[i]<min[k]))
							k=i;
						for(v[k]=1,i=0;i<n;i++)
							if(!v[i]&&min[k]+map[k][i]<min[i])
								min[i]=min[k]+map[k][i];
				}
				
				if(min[t]<inf) printf("%d\n",min[t]);
				else  printf("-1\n");
	}
return 0;
}