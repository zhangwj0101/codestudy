////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-02 15:31:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>

int cmp( const void* a, const void* b ) 
{
	int* arg1 = (int*) a;        int* arg2 = (int*) b;
	if( *arg1 < *arg2 ) return -1;
	else if( *arg1 == *arg2 ) return 0;
	else return 1;
}

main()
{
    int i,j,sum[1001],k;
    char str[1001],num[10]={'0','1','2','3','4','5','6','7','8','9'};
    while(scanf("%s",str)!=EOF)
    {
		i=0;
		while(str[i]=='5') i++;
        for(j=0,sum[0]=0;str[i]!='\0';i++)
        {
            if(str[i]!='5')
            {
                sum[j]*=10;
                for(k=0;k<10;k++)
                    if(str[i]==num[k])
                        break;
                sum[j]+=k;
            }
            else if((str[i+1]!='5')&&(str[i+1]!='\0')&&(i!=0))
            {j++;sum[j]=0;}
        }
		qsort(sum,j+1,sizeof(int),cmp);
        printf("%d",sum[0]);
        for(i=1;i<=j;i++)
            printf(" %d",sum[i]);
        printf("\n");
    }
}