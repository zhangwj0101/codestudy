////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-13 11:05:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2093
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef struct 
{
	char name[11];
	int sum;
	int total;
}C;
int cmp(const void *a,const void *b)
{
	if((*(C *)a).total!=(*(C *)b).total)
		return (*(C *)a).total-(*(C *)b).total;
	else if((*(C *)a).sum!=(*(C *)b).sum)
		return (*(C *)b).sum-(*(C *)a).sum;
	else return strcmp((*(C *)b).name,(*(C *)a).name);
}
int main(void)
{
	char style[10];
	int n,m,i,t,f,j,para;
	C c[1000]={0};
	cin>>n>>m;
	for(i=0;cin>>c[i].name;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>style;
			para=sscanf(style,"%d(%d)",&t,&f);
			if(para==2)
			{
				c[i].total++;
				c[i].sum+=t+f*m;
			}
			else if(para==1&&t>0)
			{
				c[i].total++;
				c[i].sum+=t;
			}
		}
	}
	qsort(c,i,sizeof(C),cmp);
	for(j=i-1;j>=0;j--)
		printf("%-10s %2d %4d\n",c[j].name,c[j].total,c[j].sum);
    return 0;
}