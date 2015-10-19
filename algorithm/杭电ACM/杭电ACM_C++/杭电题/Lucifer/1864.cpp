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

void Cal( int t , double money , double remain)  //t��ʾ��ǰ�ѵ��˵�t��,money��ʾ1~(t-1)���Ѿ����������remain��ʾt~k���ܶ���
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
				if( type == 'A' )  abc[0] += temp;   //ͳ��A����Ʒ���ܶ�
				else if( type == 'B' ) abc[1] += temp;  //ͳ��B����Ʒ���ܶ�
				else if( type == 'C') abc[2] += temp;  //ͳ��C����Ʒ���ܶ�
				else  tag = false;
				if( temp > 600 ) 
					tag = false;
				tot += temp;   //ͳ�Ƶ��ŷ�Ʊ�ϵ��ܶ�
			}
			
			//������ŷ�Ʊ�ܶ����1000�����κ�һ�൥���ܶ����600������෢Ʊ���ܱ���
			if( tot > 1000 || abc[0] > 600 || abc[1] > 600 || abc[2] > 600) tag = false;
			
			//�����Ա����ķ�Ʊ�ܶ��¼��ary������
			if( tag )
				ary[++k] = tot;
		}
		
		max = 0;   //max������ʾ���ı�����
		double remain = 0;  //remain������ʾʣ�����з�Ʊ���������ܶ��
		for( i = 1 ; i <= k ; i++ )  remain += ary[i];  //��ʼ��remain�������з�Ʊ���ܶ��
		Cal(1,0,remain);  //���õݹ麯����������
		
		printf( "%.2lf\n" , max );
	}
	return 1;
}