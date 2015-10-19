////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-09 22:27:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1864
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int q;
int max,ary[32],abc[4];
int k;

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

int main()
{
	int n;
	double temp;
	while( scanf( "%lf%d" , &temp , &n ) && n )
	{
		int i;
		q=(int)(temp*100);
		k = 0;
		for( i = 0 ; i < n ; i++ )
		{
			int m;
			bool tag = true;
			int tot,tempi;
			tot = 0;
			char type;
			scanf( "%d" , &m );
			abc[0] = abc[1] = abc[2] = 0;
			while( m-- )
			{
				scanf( " %c:%lf" , &type , &temp );
				tempi=(int)(temp*100);
				if( type == 'A' )  abc[0] += tempi;   //ͳ��A����Ʒ���ܶ�
				else if( type == 'B' ) abc[1] += tempi;  //ͳ��B����Ʒ���ܶ�
				else if( type == 'C') abc[2] += tempi;  //ͳ��C����Ʒ���ܶ�
				else  tag = false;
				if( tempi > 60000 ) 
					tag = false;
				tot += tempi;   //ͳ�Ƶ��ŷ�Ʊ�ϵ��ܶ�
			}
			
			//������ŷ�Ʊ�ܶ����1000�����κ�һ�൥���ܶ����600������෢Ʊ���ܱ���
			if( tot > 100000 || abc[0] > 60000 || abc[1] > 60000 || abc[2] > 60000) tag = false;
			
			//�����Ա����ķ�Ʊ�ܶ��¼��ary������
			if( tag )
				ary[++k] = tot;
		}
		
		max = 0;   //max������ʾ���ı�����
		int remain = 0;  //remain������ʾʣ�����з�Ʊ���������ܶ��
		for( i = 1 ; i <= k ; i++ )  remain += ary[i];  //��ʼ��remain�������з�Ʊ���ܶ��
		Cal(1,0,remain);  //���õݹ麯����������
		
		printf( "%.2lf\n" , max/100.0 );
	}
	return 1;
}