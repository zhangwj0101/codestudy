////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-17 23:33:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1070
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
using namespace std;
struct milk_T
{
    char brand[200];
    int volume;
    int price;
    double unit;
};
int cmp( const void *a , const void *b ) 
{ 
    struct milk_T *c = (milk_T *)a;
    struct milk_T *d = (milk_T *)b;
    if(c->unit != d->unit) return (c->unit > d->unit) ? 1 : -1; 
    else return d->volume - c->volume;
}
int main(int argc, char *argv[], char *envp[])
{
    int T,N,n;
    milk_T milk[101];
    cin>>T;
    while(T--)
    {
        cin>>N;
        for (n=0;n<N;n++)
        {
            cin>>milk[n].brand;
            cin>>milk[n].price;
            cin>>milk[n].volume;
            milk[n].unit=double(milk[n].price)/double((milk[n].volume/200>=6) ? 5 : milk[n].volume/200);
        }
        qsort(milk,n,sizeof(milk[0]),cmp);
        cout<<milk[0].brand<<endl;
    }
    return 0;    
}