////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-10 19:44:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1379
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int c,n,m,usort,i,j,k,us[100];
	char str[100][51],*sp[51];
    while(cin>>c)
    {
		while(c--)
		{
			cin>>n>>m;
			for(i=0;i<m;i++)
			{
				cin>>str[i];
				usort=0;
				for(j=0;j<n-1;j++)
					for(k=j+1;k<n;k++)
						if(str[i][j]>str[i][k])
							usort++;
				us[i]=usort;
				sp[i]=str[i];
			}
			for(i=0;i<m-1;i++)
				for(j=i+1;j<m;j++)
					if(us[i]>us[j])
					{
						swap(sp[i],sp[j]);
						swap(us[i],us[j]);
					}
			for(i=0;i<m;i++)
				cout<<sp[i]<<endl;
			if(c>0)
				cout<<endl;
		}
    }
    return 0;
}