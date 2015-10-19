////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-04 23:10:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
    int n,m,aa[110][110],v[110],min[110],ret,i,j,k,inf=(100<<16)+100;
    while(cin>>m>>n&&m){
        memset(aa,100,sizeof(aa));
        while(m--){
            cin>>i>>j>>k;
            aa[j-1][i-1]=aa[i-1][j-1]=k;
        }
        for(ret=i=0;i<n;i++) min[i]=inf,v[i]=0;
        for(min[j=0]=0;j<n;j++){
             for(k=-1,i=0;i<n;i++)
                 if(!v[i]&&(k==-1||min[i]<min[k]))k=i;
                 for(v[k]=1,ret+=min[k],i=0;i<n;i++)
                     if(!v[i]&&aa[k][i]<min[i])
                         min[i]=aa[k][i];
        }
        if(ret<inf)cout<<ret<<endl;
        else cout<<"?"<<endl;
    }
    return 0;
}