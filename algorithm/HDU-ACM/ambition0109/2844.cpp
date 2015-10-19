////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-20 15:02:21
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2844
////Problem Title: 
////Run result: Accept
////Run time:921MS
////Run memory:640KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int num[100001],v[1001],w[101];
main()
{
    int n,m,i,j,sum;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
		for(i=0;i<1001;i++) v[i]=0;
		for(i=0;i<n;i++)
			scanf("%d",&v[i*10]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<10;j++)
			{
				if(v[i*10]>=pow(2,j))
				{
					v[i*10+j+1]=(int)pow(2,j)*w[i];
					v[i*10]-=(int)pow(2,j);
				}
				else
				{
					v[i*10]*=w[i];
					break;
				}
			}
		}
        for(i=1;i<=m;i++)
            num[i]=-1;
		num[0]=0;
        for(i=0;i<n*10;i++)
        {
            for(j=m;j>=v[i];j--)
            {
				if(v[i]!=0)
				if(num[j-v[i]]!=-1)
                if(num[j-v[i]]+v[i]>num[j])
                    num[j]=num[j-v[i]]+v[i];
            }
        }
		for(i=1,sum=0;i<=m;i++)
		{
			if(num[i]!=-1) sum++;
		}
		printf("%d\n",sum);
    }
}