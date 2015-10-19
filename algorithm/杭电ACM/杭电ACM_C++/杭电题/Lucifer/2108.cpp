////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 12:49:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2108
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
bool convex=1;
void judge(int x0,int y0,int x1,int y1,int x2,int y2)
{
    int d;
    d=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);//判断是否向左拐
    if(d<0)
        convex=0;
}
int main()
{
    int x0,y0,x1,y1,x2,y2,x_0,y_0,x_1,y_1;
    int n;
    while(cin>>n&&n)
    {
		convex=1;
        cin>>x0>>y0>>x1>>y1;
        x_0=x0;y_0=y0;/******保留前两个点，用于最后特殊处理****/
        x_1=x1;y_1=y1;
        n=n-2;
        while(n--)
        {
            cin>>x2>>y2;
            judge(x0,y0,x1,y1,x2,y2);
            x0=x1;y0=y1;
            x1=x2;y1=y2;
            if(n==0)//特殊处理前面两个点
            {
                judge(x0,y0,x1,y1,x_0,y_0);
                judge(x1,y1,x_0,y_0,x_1,y_1);
            }
        }
        if(convex==0)
        {
            cout<<"concave"<<endl;
        }
        if(convex==1)
            cout<<"convex"<<endl;
    }
    return 0;
}
