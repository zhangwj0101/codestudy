////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-25 08:54:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1024
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:1820KB
//////////////////System Comment End//////////////////
/*
 * 1024.cpp
 *
 *  Created on: 2010-7-21
 *      Author: ambition
 */

#include<cstdio>
using namespace std;
#include<memory.h>

int Max[2][1000001];
int num[1000001],temp[1000001];

inline bool scan_d(int &num)
{
	char in;bool IsN=false;
	in=getchar();
	if(in==EOF) return false;
	while(in!='-'&&(in<'0'||in>'9')) in=getchar();
	if(in=='-'){ IsN=true;num=0;}
	else num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	if(IsN) num=-num;
	return true;
}
int main()
{
    int n,k;
    while(scanf("%d%d",&k,&n)!=EOF)
    {
        if(k==n){
            int sum=0;
            for(int i=0;i<n;i++){
                scan_d(num[i]);
                sum+=num[i];
            }
            printf("%d\n",sum);
            continue;
        }
        memset(Max[0],0,sizeof(int)*(n+1));
        memset(Max[1],0,sizeof(int)*(n+1));
        scan_d(num[0]);
        int F,S;F=0,S=1;
        Max[F][0]=Max[S][0]=num[0];
        for(int i=1;i<n;i++){
            scan_d(num[i]);
            if(Max[F][i-1]>0) Max[F][i]=Max[F][i-1]+num[i];
            else Max[F][i]=num[i];
            if(Max[F][i]>Max[S][i-1]) Max[S][i]=Max[F][i];
            else Max[S][i]=Max[S][i-1];
        }
        for(int i=1;i<k;i++){
        	temp[i]=Max[S][i-1]+num[i];
        	Max[F][i]=temp[i];
        	for(int j=i+1;j<n;j++){
        		if(Max[S][j-1]>temp[j-1])
        			temp[j]=Max[S][j-1]+num[j];
        		else temp[j]=temp[j-1]+num[j];
        		if(temp[j]>Max[F][j-1]) Max[F][j]=temp[j];
        		else Max[F][j]=Max[F][j-1];
        	}
        	S^=F;F^=S;S^=F;
        }
        printf("%d\n",Max[S][n-1]);
    }
}
