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
void Cal( int t , int money , int remain)  //t��ʾ��ǰ�ѵ��˵�t��,money��ʾ1~(t-1)���Ѿ����������remain��ʾt~k���ܶ���
{
	if( t > k )  //�����ǰ�㳬����ary��������Χk���򵽵���
	{
		if( max < money ) max = money;   //�������������׵�money����ǰ��¼�������max��������滻
		return;
	}
	
	
	//��������ǰ���ŷ�Ʊary[t]
	//�����ǰ��money��ʣ�����з�Ʊ���ܶ���remain-art[t]��������max����˵����ȥ�������еõ����Ž�Ŀ��ܣ�����Ͳ�ȥ�˷�ʱ��ȥ�����ˣ�������ʵ��һ����֦
	if( money + remain - ary[t] > max )   
		Cal( t+1 , money , remain-ary[t] );  //ȥ������һ��t+1,��Ϊ���㵱ǰ���ŷ�Ʊ��������Ǯ������money
	//������ǰ���ŷ�Ʊary[t]
	//������������֦���ѱ�����money�뵱ǰ���ŷ�Ʊary[t]����������Ѿ������˱����޶�q�Ͳ�������
	//�ѱ�����money��ʣ�µ����з�Ʊ���ܶ���remain������������max����û�������ı�Ҫ��
	if( money + ary[t] <= q && money + remain > max )
		Cal( t+1 , money + ary[t] , remain-ary[t] );  //ȥ������һ��t+1,��Ϊ�㵱ǰ���ŷ�Ʊ��������Ǯ����money+ary[t]
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