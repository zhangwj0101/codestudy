////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-11 20:13:23
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1708
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,k,i,j,a[26],b[26],sum[26];
	char str[31];
	for(scanf("%d",&n);n>0;n--)
	{
		for(i=0;i<26;i++)
			a[i]=b[i]=sum[i]=0;
		scanf("%s",str);
		for(i=0;str[i]!='\0';i++)
			a[str[i]-'a']+=1;
		scanf("%s",str);
		for(i=0;str[i]!='\0';i++)
			b[str[i]-'a']+=1;
		scanf("%d",&k);
		if(k==0)
			for(i=0;i<26;i++)	sum[i]=a[i];
		else if(k==1)
			for(i=0;i<26;i++)	sum[i]=b[i];
		else
			for(j=1;j<k;j++)
				for(i=0;i<26;i++)
				{
					sum[i]=a[i]+b[i];
					a[i]=b[i];
					b[i]=sum[i];
				}
		for(i=0;i<26;i++)
			printf("%c:%d\n",i+'a',sum[i]);
		printf("\n");
	}
}