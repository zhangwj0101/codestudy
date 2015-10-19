////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-23 10:02:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1253
////Problem Title: 
////Run result: Accept
////Run time:1171MS
////Run memory:412KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<queue>
using namespace std;

void scan_bool(bool& tof)
{
	char ch;ch=getchar();
	while(ch!='1'&&ch!='0')
		ch=getchar();
	if(ch=='1') tof=true;
	else tof=false;
}
struct step{
	int x,y,z,t;
	step(int nx,int ny,int nz,int nt):x(nx),y(ny),z(nz),t(nt){}
};
int Dir[6][3]={{0,0,1},{0,1,0},{1,0,0},{0,0,-1},{0,-1,0},{-1,0,0}};
queue<step> qstep;
bool map[51][51][51];
void main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--){
		int x,y,z,t;
		scanf("%d%d%d%d",&z,&y,&x,&t);
		for(int i=0;i<z;i++)
			for(int j=0;j<y;j++)
				for(int k=0;k<x;k++)
					scan_bool(map[i][j][k]);
		while(!qstep.empty()) qstep.pop();
		step start(0,0,0,0);
		map[0][0][0]=true;
		qstep.push(start);
		while(!qstep.empty()){
			for(int i=0;i<6;i++){
				int tx=qstep.front().x+Dir[i][2],ty=qstep.front().y+Dir[i][1],tz=qstep.front().z+Dir[i][0];
				if(tz>=0&&tz<z&&ty>=0&&ty<y&&tx>=0&&tx<x)
					if(!map[tz][ty][tx]){
						step temp(tx,ty,tz,qstep.front().t+1);
						if(temp.t>t){
							printf("-1\n");
							goto end;
						}
						if((tx==x-1)&&(ty==y-1)&&(tz==z-1)){
							printf("%d\n",temp.t);
							goto end;
						}
						map[tz][ty][tx]=true;
						qstep.push(temp);
					}
			}
			qstep.pop();
			
		}
		printf("-1\n");
end:	continue;
	}
}