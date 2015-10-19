////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-24 21:47:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3088
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:468KB
//////////////////System Comment End//////////////////
/*
 * 3088.cpp
 *
 *  Created on: 2010-9-24
 *      Author: administrator
 */

#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int len;
struct Array{
	int arr[11];
	int turn()
	{
		int ans=0;
		for(int i=0,j=1;i<len;i++,j*=3){
			ans+=arr[i]*j;
		}
		return ans;
	}
};
struct Unit{
	Array bug;
	int step;
	void set(Array nb,int ns){
		bug=nb;
		step=ns;
	}
};

Array start;
bool Hash[200000];
int Bfs()
{
	queue<Unit> Que;
	Unit tmp;
	tmp.set(start,0);
	Que.push(tmp);
	Hash[start.turn()]=true;
	while(!Que.empty()){
		Array tb=Que.front().bug;
		int ts=Que.front().step;
		Que.pop();
		for(int i=1;i<len;i++){
			Array ttb(tb);
			if(ttb.arr[i]!=ttb.arr[i-1]){
				if(ttb.arr[i]!=0&&ttb.arr[i-1]!=0){
					ttb.arr[i]=0;ttb.arr[i-1]=0;
				}else if(ttb.arr[i]!=1&&ttb.arr[i-1]!=1){
					ttb.arr[i]=1;ttb.arr[i-1]=1;
				}else if(ttb.arr[i]!=2&&ttb.arr[i-1]!=2){
					ttb.arr[i]=2;ttb.arr[i-1]=2;
				}
				int tth=ttb.turn();
				if(Hash[tth]) continue;
				bool flag=true;
				for(int i=1;i<len;i++){
					if(ttb.arr[i]!=ttb.arr[i-1]){
						flag=false;
						break;
					}
				}
				if(flag) return ts+1;
				Hash[tth]=true;
				tmp.set(ttb,ts+1);
				Que.push(tmp);
			}
		}
	}
	return -1;
}

int main()
{
	int t;
	char str[15];
	scanf("%d",&t);
	while(t--){
		memset(Hash,false,sizeof(Hash));
		scanf("%s",str);
		len=strlen(str);
		for(int i=0;i<len;i++){
			if(str[i]=='r') start.arr[i]=0;
			else if(str[i]=='g') start.arr[i]=1;
			else if(str[i]=='b') start.arr[i]=2;
		}
		bool flag=true;
		for(int i=1;i<len;i++){
			if(start.arr[i]!=start.arr[i-1]){
				flag=false;
				break;
			}
		}
		if(flag){
			puts("0");
			continue;
		}
		int ans=Bfs();
		if(ans==-1) puts("No solution!");
		else printf("%d\n",ans);
	}
}

