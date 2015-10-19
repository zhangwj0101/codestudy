////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-05-31 17:10:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2812
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int main()
{
	int count,m,n,t,i,j,k,index,temp,flag;
	int a[11];
	double b[11],p;
	while(scanf("%d",&t)!=EOF)
	{     count=0;flag=0;
	for(i=0;i<t;i++)
	{
		scanf("%d%lf",&a[i],&b[i]);
		if(a[i]==14&&b[i]==5.0)count++;
		if(a[i]==7&&b[i]>=0&&b[i]<=0.8)count++;
	}
	if(count==2)printf("Yes\n");
	else {flag=1;printf("No\n");}
	for(k=0;k<t-1;k++)
	{index=k;if(a[k]==14||a[k]==7)a[k]=-1;
	for(j=k+1;j<t;j++)
		if(a[index]>a[j])index=j;
		temp=a[index];
		a[index]=a[k];
		a[k]=temp;
		p=b[index];
		b[index]=b[k];
		b[k]=p;
	}
	for(i=0;i+1<t;i=i+2)
	{
		if(flag==1)break;
		if(a[i]!=-1){
			if(fabs(b[i]-5.0)<=0.5)m=1;
			else m=0;
			if(fabs(b[i+1]-5.0)<=0.5)n=1;
			else n=0;
			if(a[i]==1&&a[i+1]==2&&m*n==0)printf("3 H\n");
			else if(a[i]==1&&a[i+1]==2&&m*n==1)printf("3 L\n");
			else if(a[i]==4&&a[i+1]==5&&m*n==0)printf("6 H\n");
			else if(a[i]==4&&a[i+1]==5&&m*n==1)printf("6 L\n");
			else if(a[i]==9&&a[i+1]==10&&m*n==0)printf("8 H\n");
			else if(a[i]==9&&a[i+1]==10&&m*n==1)printf("8 L\n");
			else if(a[i]==12&&a[i+1]==13&&m*n==0)printf("11 H\n");
			else if(a[i]==12&&a[i+1]==13&&m*n==1)printf("11 L\n");
		}
	}
	}
	return 0;
}