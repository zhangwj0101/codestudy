////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-24 17:22:29
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int i,q,x,sum,k;
	char n[13],num[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	while(1)
	{
		for(k=0,sum=0;k<2;k++)
		{
			x=0;
			for(i=0;n[i-1]!='+'&&n[i-1]!='=';i++)
				n[i]=getchar();
			n[i-1]='\0';
			for(q=0;q<10;q++)
				if(n[0]==num[q][0]&&n[1]==num[q][1])
					break;
			x+=q;
			i=0;
			while(n[i]!=' ')
				i++;
			if(n[i+1]!='\0')
			{
				x*=10;
			for(q=0;q<10;q++)
				if(n[i+1]==num[q][0]&&n[i+2]==num[q][1])
					break;
				x+=q;
			}
			sum+=x;
			getchar();
		}
		if(sum==0)
			break;
		printf("%d\n",sum);
	}
}