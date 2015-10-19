////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-19 20:54:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include"stdio.h"
int main(void)
{
	int a,b,n,i,f[100],x;
	while(scanf("%d%d%d",&a,&b,&n)!=EOF)
	{
		if(!(a||b||n)){
			break;
		}
		if((n==1)||(n==2)){
			printf("1\n");
			continue;
		}else{
			f[1]=1,f[2]=1;
			for(i=3;i<100;i++){
				f[i]=(a*f[i-1]+b*f[i-2])%7;
				if((f[i-1]==1)&&(f[i]==1))
					break;
			}
			x=i-2;
			n=(n-1)%x+1;
			printf("%d\n",f[n]);
		}
	}
	return 0;
}