////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-10 20:06:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3577
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:16644KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 999999

int beg, end;
int tree[2097152];
int all[2097152];

int query( int, int, int );
void add( int, int, int );

main (){
	int t, T, tt = 0;
	int k, Q;
	
	scanf ( "%d", &T );
	while( T -- ){
		scanf ( "%d %d", &t, &Q );
		memset ( tree, 0, sizeof ( tree ) );
		memset ( all, 0, sizeof ( all ) );
		k = 0;
		printf( "Case %d:\n", ++ tt );
		for ( k = 0; k < Q; k ++ ){
			scanf ( "%d %d", &beg, &end );
			end --;
			if ( query( 1, 1, MAX ) < t ){
				printf ( "%d ", k + 1 );
				add( 1, 1, MAX );
			}
		}
		printf ( "\n\n" );
	}
	
	return 0;
}

int query( int k, int b, int e ){
	if ( beg <= b && end >= e )
		return all[k];
	
	int m = ( b + e ) / 2;
	if ( beg > m )
		return tree[k] + query( k * 2 + 1, m + 1, e );
	
	if ( end <= m )
		return tree[k] + query( k * 2, b, m );
	
	return tree[k] + max( query( k * 2, b, m ), query( k * 2 + 1, m + 1, e ) );
}

void add( int k, int b, int e ){
	if ( beg <= b && end >= e ){
		tree[k] ++;
		all[k] ++;
		return;
	}
	
	int m = ( b + e ) / 2;
	if ( beg > m ){
		add( k * 2 + 1, m + 1, e );
		all[k] = max ( all[ k * 2 ], all[ k * 2 + 1 ] ) + tree[k];
		return;
	}
	
	if ( end <= m ){
		add( k * 2, b, m );
		all[k] = max ( all[ k * 2 ], all[ k * 2 + 1 ] ) + tree[k];
		return;
	}
	
	add( k * 2, b, m );
	add( k * 2 + 1, m + 1, e );
	all[k] = max ( all[ k * 2 ], all[ k * 2 + 1 ] ) + tree[k];
}
