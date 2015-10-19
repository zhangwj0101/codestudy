////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-09 21:52:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3773
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int tpos[1005];
int tid[1005];
bool need[1005];
bool flag[1005];
int stk[1005];
char str[1005];
int main(){
	while(~scanf("%s",str)){
		int id=0,top=0;
		memset(need,true,sizeof(need));
		for(int i=0;str[i];i++){
			if(str[i]=='('){
				flag[top]=true;
				tid[i]=id;
				stk[top++]=id++;
			}else if(str[i]==')'){
				int tmp=stk[--top];
				tid[i]=tmp;
				if(flag[top]) need[tmp]=false;
			}else if(str[i]=='+'&&top>0){
				flag[top-1]=false;
			}
		}
		
		int j=0;
		for(int i=0;str[i];i++){
			if(str[i]=='('||str[i]==')'){
				if(!need[tid[i]]) continue;
			}
			str[j++]=str[i];
		}
		str[j]=0;
		
		id=0;
		memset(need,true,sizeof(need));
		for(int i=0;str[i];i++){
			if(str[i]=='('){
				tid[i]=id;
				tpos[id]=i;
				stk[top++]=id++;
			}else if(str[i]==')'){
				int tmp=stk[--top];
				tid[i]=tmp;
				if(str[i+1]==0||str[i+1]=='+'||str[i+1]==')'){
					int ti=tpos[tmp];
					if(ti-1<0||str[ti-1]=='+'||str[ti-1]=='('){
						need[tmp]=false;
					}
				}
			}
		}
		
		for(int i=0;str[i];i++){
			if(str[i]=='('||str[i]==')'){
				if(need[tid[i]]) putchar(str[i]);
			}else putchar(str[i]);
		}
		puts("");
	}
}