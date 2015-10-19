////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-08 13:08:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1301
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int str[500][3],sign[500];
main()
{
	int n,m,i,ii,j,k1,k2,t,city[30],count,s;
	char ch1,ch2;
	while(scanf("%d",&n),getchar(),n)
	{
		for(i=0,ii=0;i<n-1;i++)
			for(scanf("%c%d",&ch1,&m),getchar();m>0;m--,ii++)
			{
				scanf("%c%d",&ch2,&t);getchar();
				str[ii][0]=ch1-'A',str[ii][1]=ch2-'A';
				str[ii][2]=t;
			}
		for(i=0;i<ii;i++)
			sign[i]=i;
		for(i=0;i<30;i++)
			city[i]=i;
		for(i=0,count=0,s=0;i<ii;i++)
		{
			for(j=i+1;j<ii;j++)
				if(str[sign[i]][2]>str[sign[j]][2])
				{t=sign[i];sign[i]=sign[j];sign[j]=t;}
			k1=city[str[sign[i]][0]];
			while(city[k1]!=k1)
				k1=city[k1];
			k2=city[str[sign[i]][1]];
			while(city[k2]!=k2)
				k2=city[k2];
			if(k1!=k2)
			{
				if(city[k2]>city[k1])
					city[k2]=city[str[sign[i]][0]];
				else
					city[k1]=city[str[sign[i]][1]];
				count++;s+=str[sign[i]][2];
			}
			if(count==n-1)
				break;
		}
			printf("%d\n",s);
	}
}