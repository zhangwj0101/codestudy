////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-09 22:38:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1864
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int k,q;
int price[32];
int *ary;
int max;
// int cal(int floor,int v,int remain)
// {
// 	int ret,ret2;
// 	if ((v+remain>max)&&(floor<=k))
// 	{
// 		remain-=price[floor];
// 		ret2=cal(floor+1,v,remain);
// 		if (v+price[floor]<=q)
// 		{
// 			ret=cal(floor+1,v+price[floor],remain);
// 		}
// 		ret=ret>ret2?ret:ret2;
// 		if (ret>max)
// 		{
// 			max=ret;
// 		}
// 		return ret;
// 	}
// 	if (v>max)
// 	{
// 		max=v;
// 	}
// 	return v;
// }
void Cal( int t , int money , int remain)  //t表示当前搜到了第t层,money表示1~(t-1)层已经报销的数额，remain表示t~k的总额数
{
	if( t > k )  //如果当前层超出了ary数组的最大范围k，则到底了
	{
		if( max < money ) max = money;   //如果这次搜索到底的money比以前记录的最大额度max大，则进行替换
		return;
	}
	
	
	//不报销当前这张发票ary[t]
	//如果当前的money与剩下所有发票的总额数remain-art[t]加起来比max大，则说明进去搜索还有得到更优解的可能，否则就不去浪费时间去搜索了，这里其实是一个剪枝
	if( money + remain - ary[t] > max )   
		Cal( t+1 , money , remain-ary[t] );  //去搜索下一层t+1,因为不算当前这张发票，所以总钱数还是money
	//报销当前这张发票ary[t]
	//这里是两个剪枝，已报销的money与当前这张发票ary[t]加起来如果已经超过了报销限额q就不用搜了
	//已报销的money与剩下的所有发票的总额数remain加起来都不如max大，则没有搜索的必要了
	if( money + ary[t] <= q && money + remain > max )
		Cal( t+1 , money + ary[t] , remain-ary[t] );  //去搜索下一层t+1,因为算当前这张发票，所以总钱数是money+ary[t]
}


void main()
{
	int n,m,i;
	int p,sum;
	double pp;
	char type;
	char flag;
	ary=price;
	int abc[4];
	while (scanf("%lf%d",&pp,&n),n)
	{
		k=0;
		q=(int)(pp*100);
		max=0;
		while(n--)
		{
			scanf("%d",&m);
			flag=1;
			sum=0;
			memset(abc,0,sizeof(abc));
			while (m--)
			{
				scanf(" %c:%lf",&type,&pp);
				p=(int)(pp*100);
				
				
				if ((type>='A')&&(type<='C')&&(p<=60000))
				{
					abc[type-'A']+=p;
					sum+=p;
				}
				else
					flag=0;
			}
			if (sum>100000||abc[0]>60000||abc[1]>60000||abc[2]>60000)
			{
				flag=0;
			}
			if (flag)
				price[++k]=sum;
		}
		int remain=0;
		for (i=1;i<=k;i++)
		{
			remain+=price[i];
		}
		Cal(1,0,remain);
		printf("%.2lf\n",max/100.0);
	}
}