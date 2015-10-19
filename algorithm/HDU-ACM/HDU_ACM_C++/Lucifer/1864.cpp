////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-09 20:11:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1864
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>

double ary[32],max,q,abc[4];
int k;

void Cal( int t , double money , double remain)  //t表示当前搜到了第t层,money表示1~(t-1)层已经报销的数额，remain表示t~k的总额数
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

int main()
{
	int n;
	while( scanf( "%lf%d" , &q , &n ) && n )
	{
		int i;
		k = 0;
		for( i = 0 ; i < n ; i++ )
		{
			int m;
			bool tag = true;
			double tot,temp;
			tot = 0;
			char type;
			scanf( "%d" , &m );
			abc[0] = abc[1] = abc[2] = 0;
			while( m-- )
			{
				scanf( " %c:%lf" , &type , &temp );
				if( type == 'A' )  abc[0] += temp;   //统计A类物品的总额
				else if( type == 'B' ) abc[1] += temp;  //统计B类物品的总额
				else if( type == 'C') abc[2] += temp;  //统计C类物品的总额
				else  tag = false;
				if( temp > 600 ) 
					tag = false;
				tot += temp;   //统计单张发票上的总额
			}
			
			//如果单张发票总额大于1000，或任何一类单项总额大于600，则此类发票不能报销
			if( tot > 1000 || abc[0] > 600 || abc[1] > 600 || abc[2] > 600) tag = false;
			
			//将可以报销的发票总额记录到ary数组中
			if( tag )
				ary[++k] = tot;
		}
		
		max = 0;   //max用来表示最大的报销额
		double remain = 0;  //remain用来表示剩下所有发票加起来的总额度
		for( i = 1 ; i <= k ; i++ )  remain += ary[i];  //初始化remain，是所有发票的总额度
		Cal(1,0,remain);  //调用递归函数进行搜索
		
		printf( "%.2lf\n" , max );
	}
	return 1;
}