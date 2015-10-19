////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-05 20:04:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:260KB
//////////////////System Comment End//////////////////
/*
 * 2138.cpp
 *
 *  Created on: 2010-12-5
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int num[10000];
bool Hash[10000];
int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(Hash,false,sizeof(Hash));
		int Max=0,cnt=n;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			if((num[i]&1)){
				if(num[i]>Max) Max=num[i];
			}else{
				Hash[i]=true;
				if(num[i]!=2) cnt--;
			}
		}

		for(int i=3;i<=(int)sqrt(double(Max));i+=2){
			for(int j=0;j<n;j++){
				if(!Hash[j]&&i*i<=num[j]){
					if(!(num[j]%i)){
						cnt--;
						Hash[j]=true;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
}
