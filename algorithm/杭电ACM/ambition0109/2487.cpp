////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 14:50:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2487
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
/*
 * hdu0922.cpp
 *
 *  Created on: 2010-9-22
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;

char scr[105][105];
bool Hash[30];
bool top[30];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		memset(Hash,false,sizeof(Hash));
		memset(top,false,sizeof(top));
		for(int i=0;i<n;i++){
			scanf("%s",scr[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(scr[i][j]=='.'){
					continue;
				}
				char tmp=scr[i][j];
				if(Hash[tmp-'A']) continue;
				Hash[tmp-'A']=true;
				int l=0,w=0;

				for(int jj=j;jj<m;jj++){
					if(scr[i][jj]==tmp){
						l++;
					}else break;
				}
				if(l<3) continue;

				for(int ii=i;ii<n;ii++){
					if(scr[ii][j]==tmp){
						w++;
					}else break;
				}
				if(w<3) continue;

				for(int jj=j;jj<j+l;jj++){
					if(scr[i+w-1][jj]!=tmp){
						goto CONTINUE;
					}
				}
				for(int ii=i;ii<i+w;ii++){
					if(scr[ii][j+l-1]!=tmp){
						goto CONTINUE;
					}
				}

				for(int ii=i+1;ii<i+w-1;ii++){
					for(int jj=j+1;jj<j+l-1;jj++){
						if(scr[ii][jj]!='.'){
							goto CONTINUE;
						}
					}
				}
				top[tmp-'A']=true;
				CONTINUE:
				continue;
			}
		}
		for(int i=0;i<26;i++){
			if(top[i]){
				printf("%c",i+'A');
			}
		}
		puts("");
	}
}
