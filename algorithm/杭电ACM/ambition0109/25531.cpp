////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 20:38:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2553
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:180KB
//////////////////System Comment End//////////////////
/*
 * 2553.cpp
 *
 *  Created on: 2010-8-20
 *      Author: ambition
 */

#include<cstdio>
#include<cmath>
using namespace std;
//const int MAX=6;
//
//int set[10];
//bool check(int n){
//	int i;
//	for(i=0;i<n;i++){
//		if(set[i]==set[n]) break;
//		if((int)abs(double(set[i]-set[n]))==n-i) break;
//	}
//	if(i==n) return true;
//	else return false;
//}
//
//int main()
//{
//	int count=0;
//	for(set[0]=0;set[0]<MAX;set[0]++){
//		for(set[1]=0;set[1]<MAX;set[1]++){
//			if(!check(1)) continue;
//			for(set[2]=0;set[2]<MAX;set[2]++){
//				if(!check(2)) continue;
//				for(set[3]=0;set[3]<MAX;set[3]++){
//					if(!check(3)) continue;
//					for(set[4]=0;set[4]<MAX;set[4]++){
//						if(!check(4)) continue;
//						for(set[5]=0;set[5]<MAX;set[5]++){
//							if(!check(5)) continue;
//							for(set[6]=0;set[6]<MAX;set[6]++){
//								if(!check(6)) continue;
//								for(set[7]=0;set[7]<MAX;set[7]++){
//									if(!check(7)) continue;
//									for(set[8]=0;set[8]<MAX;set[8]++){
//										if(!check(8)) continue;
//										for(set[9]=0;set[9]<MAX;set[9]++){
//											if(!check(9)) continue;
//											count++;
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	printf("%d\n",count);
//}

int num[11]={0,1,0,0,2,10,4,40,92,352,724};
int main()
{
	int n;
	while(scanf("%d",&n),n){
		printf("%d\n",num[n]);
	}
}
