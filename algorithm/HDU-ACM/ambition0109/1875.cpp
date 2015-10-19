////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-08 14:58:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1875
////Problem Title: 
////Run result: Accept
////Run time:765MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int str[10000][2],sign[10000];
double dis[10000];
main()
{
    int n,m,i,j,city[150],k1,k2,t,count,o;
    double s,x[150],y[150],d;
    for(scanf("%d",&o);o>0;o--)
	{
		
        for(scanf("%d",&n),i=0;i<n;i++)
        {
            city[i]=i;
            scanf("%lf%lf",&x[i],&y[i]);
        }
        for(i=0,m=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
            {
				d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				if(d<=1000000&&d>=100)
				{
					str[m][0]=i;str[m][1]=j;
					dis[m]=d;
					m++;
				}
            }
		for(i=0;i<m;i++)
			sign[i]=i;
        for(count=0,s=0,i=0;i<m;i++)
        {
            for(j=i+1;j<m;j++)
                if(dis[sign[i]]>dis[sign[j]])
                {t=sign[i];sign[i]=sign[j];sign[j]=t;}
            k1=str[sign[i]][0];
            while(city[k1]!=k1)
                k1=city[k1];
            k2=str[sign[i]][1];
            while(city[k2]!=k2)
                k2=city[k2];
            if(k1!=k2)
            {
                if(city[k2]>city[k1])
                    city[k2]=city[str[sign[i]][0]];
                else
                    city[k1]=city[str[sign[i]][1]];
                count++;s+=sqrt(dis[sign[i]]);
            }
            if(count==n-1)
                break;
        }
		if(count<n-1)
			printf("oh!\n");
		else
			printf("%.1lf\n",s*100);
    }
}