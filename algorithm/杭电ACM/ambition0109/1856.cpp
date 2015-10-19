////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-08 15:19:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1856
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:78564KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int city[10000001],count[10000001];
main()
{
    int n,i,k1,k2,str[2],t,max;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<10000001;i++)
		{city[i]=i;count[i]=0;}
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&str[0],&str[1]);
            k1=str[0];
            while(city[k1]!=k1)
                k1=city[k1];
            k2=str[1];
            while(city[k2]!=k2)
                k2=city[k2];
            if(k1!=k2)
            {
                if(city[k2]>city[k1])
                    city[k2]=city[str[0]];
                else
                    city[k1]=city[str[1]];
            }
        }
		for(i=1,max=0;i<10000001;i++)
		{
			t=i;
			while(city[t]!=t)
				t=city[t];
			count[t]++;
			if(count[t]>max)
				max=count[t];
		}
        printf("%d\n",max);
    }
}