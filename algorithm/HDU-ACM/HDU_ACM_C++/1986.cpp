////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-12-01 15:55:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1986
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream> 
#include<string> 
using namespace std; 
int dir[4][2]={0,1,1,0,0,-1,-1,0}; 
int g[25][25]; 
bool hash[25][25]; 
string f(char t){  //得到2进制的函数，经测试，' ','A'~'Z',都能正确得到结果 
	if(t==' ') return "00000"; 
	int a=t-'A'+1,i=5; 
	string m="00000"; 
	while(a>0){ 
		m[--i]=a%2+'0'; 
		a/=2; 
	} 
	return m; 
} 
//思想：把输入的字符串按序翻译成一个长串，记录在string s； 
//再按旋转的路径把s的字符(0或1)一一赋给int数组g…… 
int main(){ 
	int i,j,n,m,tt,k,a,b,x,y,aa,bb,ala=0; 
	bool bo; 
	char t[100]; 
	cin>>tt; 
	while(tt--){ 
		string s; 
		cin>>n>>m; 
		getchar(); 
		gets(t); 
		for(i=0;i<strlen(t);i++) 
			s=s+f(t[i]); 
		//cout<<"s="<<s<<endl; 
		memset(g,0,sizeof(g)); 
		memset(hash,0,sizeof(hash)); 
		////////以下主要是在模拟它旋转的路径，用类似dfs的方法模拟(写得有点乱) 
		////////测试数据输出的路径都是对的…… 
		bo=1;x=0,y=0,k=0; 
		while(bo && k<s.length()) 
		{ 
			hash[x][y]=1; 
			g[x][y]=s[k++]-'0'; 
			for(bo=0,i=0;i<4;i++){ 
				a=x+dir[i][0]; 
				b=y+dir[i][1]; 
				if(a<n&&b<m&&a>-1&&b>-1&&!hash[a][b]){ 
					if(i==0){ 
						aa=x+dir[3][0],bb=y+dir[3][1]; 
						if(aa<n&&bb<m&&aa>-1&&bb>-1&&!hash[aa][bb]){ 
							x=aa;y=bb;bo=1; 
							break; 
						} 
					} 
					x=a;y=b;bo=1; 
					break; 
				} 
			} 
		} 
		cout<<++ala<<" ";//ala计录测试次数 
		for(i=0;i<n;i++) 
			for(j=0;j<m;j++) 
				cout<<g[i][j]; 
			cout<<endl; 
	} 
	return 0; 
} 