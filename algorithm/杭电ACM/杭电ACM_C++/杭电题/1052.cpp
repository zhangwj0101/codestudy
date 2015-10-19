////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-01 18:42:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1052
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
//̰�� 
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int t[1100],k[1100];

int main()
{
	int i,j,i2,j2;
	
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&t[i]);
		for(i=0;i<n;i++)
			scanf("%d",&k[i]);
		sort(t,t+n);
		sort(k,k+n);
		m=0;
		i=0;j=n-1;i2=0;j2=n-1;
		for(;j2>=0 && j>=0 && j>=i;j--,j2--)
		{
			if(k[j2]>t[j])//�ʵۺ��� > ��ɺ��� , ����� , ������ 
			{
				m-=200;
				i++;j++;
			}
			else if(k[j2]<t[j])//�ʵۺ��� < ��ɺ��� , ���Ӯ , �ú��� 
			{
				m+=200;
			}
			else//��ͬ�ĺ��� 
			{
					while(k[i2]<t[i] && i<j)//�ʵ����� < ������� , ���Ӯ 
					{
						m+=200;
						i++;i2++;
					}
					if(i!=j)//�ʵ����� >= �������
					{
						if(k[j2]>t[i])
							m-=200;
						i++;j++;
					}
			}

		}
		printf("%d\n",m);
	}
	return 0;
}
