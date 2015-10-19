////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-10 20:05:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3577
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:23720KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define SIZE 1001000
int cnt[3000000], mx[3000000];
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
void over( int b, int e, int id=0, int ib=0, int ie=SIZE ) {
	if ( ib==b && ie==e ) {
		cnt[id]++;
		mx[id]++;
		return ;
	}
	
	int mid = (ib+ie)/2;
	if (b>mid) over( b, e, R(id), mid+1, ie );
	else if (e<=mid) over( b, e, L(id), ib, mid );
	else {
		over( b, mid, L(id), ib, mid );
		over( mid+1, e, R(id), mid+1, ie );
	}
	mx[id]= max( mx[L(id)], mx[R(id)] )+cnt[id];
}

int query( int b, int e, int id=0, int ib=0, int ie=SIZE ) {
	if ( b==ib && e==ie ) return mx[id];
	
	int mid = (ib+ie)/2;
	if (b>mid) return cnt[id]+query( b, e, R(id), mid+1, ie );
	else if (e<=mid) return cnt[id]+query( b, e, L(id), ib, mid );
	else {
		int m=query( b, mid, L(id), ib, mid );
		int n=query( mid+1, e, R(id), mid+1, ie );
		return max(m, n)+cnt[id];
	}
}

int main () {
	int k, cn, cs;
	scanf ("%d",&cn);
	for (cs=1;cs<=cn;cs++){
		printf("Case %d:\n", cs);
		scanf("%d",&k);
		memset( cnt, 0, sizeof(cnt) );
		memset( mx, 0, sizeof(mx) );
		int a, b, c, t, Q;
		scanf("%d",&Q);
		for (c=1;c<=Q;c++){
			scanf ("%d%d",&a,&b);
			t=query(a,b-1);
			if ( t<k ) {
				over(a,b-1);
				printf("%d ",c);
			}
		}
		printf ("\n\n");
	}
	return 0;
}
