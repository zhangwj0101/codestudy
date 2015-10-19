////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-25 09:49:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1024
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:1808KB
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
    while(scan_d(k)&&scan_d(n))
    {
        memset(Max[0],0,sizeof(int)*(n+1));
        memset(Max[1],0,sizeof(int)*(n+1));
        int F=1,S=0;
        for(int i=1;i<=n;i++)
            scan_d(num[i]);
		Max[F][1]=temp[1]=num[1];
        for(int i=1;i<=k;i++){
        	temp[i]=Max[S][i-1]+num[i];
        	Max[F][i]=temp[i];
        	for(int j=i+1;j<=n;j++){
        		if(Max[S][j-1]>temp[j-1])
        			temp[j]=Max[S][j-1]+num[j];
        		else temp[j]=temp[j-1]+num[j];
        		if(temp[j]>Max[F][j-1]) Max[F][j]=temp[j];
        		else Max[F][j]=Max[F][j-1];
        	}
        	S=F;F=S^1;
        }
        printf("%d\n",Max[S][n]);
    }
}