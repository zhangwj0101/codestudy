////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-20 09:48:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2598
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int map[101][101];
int maps[101][101];
int sx,sy,ssx,ssy;
bool IsM;
void main()
{
	int n;
	string line;
	cin>>n;
	while(cin){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				cin>>map[i][j];
				maps[i][j]=map[i][j];
				if(map[i][j]==0)
					ssy=sy=i,ssx=sx=j;
			}
		while(getline(cin,line)){
			stringstream ss(line);
			if(!ss) return;
			string cmd;
			while(ss>>cmd){
				if(cmd[0]<='9'&&cmd[0]>='0'){
					n=cmd[0]-'0';
					for(unsigned i=1;i<cmd.length();i++){
						n*=10;n+=cmd[i]-'0';
					}
					for(int i=1;i<=n;i++)
						for(int j=1;j<=n;j++){
							cin>>map[i][j];
							maps[i][j]=map[i][j];
							if(map[i][j]==0)
								ssy=sy=i,ssx=sx=j;
						}
				}else if(cmd=="SHOW"){
					for(int i=1;i<=n;i++){
						for(int j=1;j<=n;j++){
							if(j!=1) cout<<' ';
							cout<<maps[i][j];
						}
						cout<<endl;
					}
					cout<<endl;
				}else if(cmd=="MOVE"){
					IsM=true;
					while(ss>>cmd)
					{
						if(IsM){
							if(cmd=="up"){
								if(sy-1>0){
									map[sy][sx]^=map[sy-1][sx];
									map[sy-1][sx]^=map[sy][sx];
									map[sy][sx]^=map[sy-1][sx];
									sy-=1;
								}else IsM=false;
							}else if(cmd=="down"){
								if(sy+1<=n){
									map[sy][sx]^=map[sy+1][sx];
									map[sy+1][sx]^=map[sy][sx];
									map[sy][sx]^=map[sy+1][sx];
									sy+=1;
								}else IsM=false;
							}else if(cmd=="left"){
								if(sx-1>0){
									map[sy][sx]^=map[sy][sx-1];
									map[sy][sx-1]^=map[sy][sx];
									map[sy][sx]^=map[sy][sx-1];
									sx-=1;
								}else IsM=false;
							}else if(cmd=="right"){
								if(sx+1<=n){
									map[sy][sx]^=map[sy][sx+1];
									map[sy][sx+1]^=map[sy][sx];
									map[sy][sx]^=map[sy][sx+1];
									sx+=1;
								}else IsM=false;
							}
						}
					}
					if(IsM){
						cout<<"MOVED"<<endl;
						for(int i=1;i<=n;i++)
							for(int j=1;j<=n;j++)
								maps[i][j]=map[i][j];
					}else{
						cout<<"FAILED"<<endl;
						for(int i=1;i<=n;i++)
							for(int j=1;j<=n;j++)
								map[i][j]=maps[i][j];
					}
				}
			}
		}
	}
}