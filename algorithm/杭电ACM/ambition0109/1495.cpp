////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-24 18:12:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1495
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1276KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
using namespace std;

struct coke{
    int v,a,b,t;
    coke (){}
    coke (int nv,int na,int nb,int nt):v(nv),a(na),b(nb),t(nt){}
    void set(int nv,int na,int nb,int nt){
        v=nv;a=na;b=nb;t=nt;
    }
};
int av,aa,ab;
bool Hash[101][101][101];
queue<coke> cap;
int Bfs(int v)
{
    coke temp;
    while(!cap.empty()){
        int tv=cap.front().v,ta=cap.front().a,tb=cap.front().b;
        int tt=cap.front().t;
        int ttv,tta,ttb;
        if((aa-ta)!=0){
            if(tv!=0){
                ttv=(tv-(aa-ta))>0?(tv-(aa-ta)):0;
                tta=(tv-(aa-ta))>0?aa:(ta+tv);
                ttb=tb;
                if(!Hash[ttv][tta][ttb]){
                    if(ttv==av/2&&(tta==av/2||ttb==av/2))
                        return tt+1;
                    Hash[ttv][tta][ttb]=true;
                    temp.set(ttv,tta,ttb,tt+1);
                    cap.push(temp);
                }
            }
            if(tb!=0){
                ttv=tv;
                tta=(tb-(aa-ta))>0?aa:(ta+tb);
                ttb=(tb-(aa-ta))>0?(tb-(aa-ta)):0;
                if(!Hash[ttv][tta][ttb]){
                    if(ttv==av/2&&(tta==av/2||ttb==av/2))
                        return tt+1;
                    Hash[ttv][tta][ttb]=true;
                    temp.set(ttv,tta,ttb,tt+1);
                    cap.push(temp);
                }
            }
        }
        if((ab-tb)!=0){
            if(tv!=0){
                ttv=(tv-(ab-tb))>0?(tv-(ab-tb)):0;
                tta=ta;
                ttb=(tv-(ab-tb))>0?ab:(tb+tv);
                if(!Hash[ttv][tta][ttb]){
                    if(ttv==av/2&&(tta==av/2||ttb==av/2))
                        return tt+1;
                    Hash[ttv][tta][ttb]=true;
                    temp.set(ttv,tta,ttb,tt+1);
                    cap.push(temp);
                }
            }
            if(ta!=0){
                ttv=tv;
                tta=(ta-(ab-tb))>0?(ta-(ab-tb)):0;
                ttb=(ta-(ab-tb))>0?ab:(tb+ta);
                if(!Hash[ttv][tta][ttb]){
                    if(ttv==av/2&&(tta==av/2||ttb==av/2))
                        return tt+1;
                    Hash[ttv][tta][ttb]=true;
                    temp.set(ttv,tta,ttb,tt+1);
                    cap.push(temp);
                }
            }    
        }
        if((av-tv)!=0){
            if(ta!=0){
                ttv=(ta-(av-tv))>0?av:(ta+tv);
                tta=(ta-(av-tv))>0?(ta-(av-tv)):0;
                ttb=tb;
                if(!Hash[ttv][tta][ttb]){
                    if(ttv==av/2&&(tta==av/2||ttb==av/2))
                        return tt+1;
                    Hash[ttv][tta][ttb]=true;
                    temp.set(ttv,tta,ttb,tt+1);
                    cap.push(temp);
                }
            }
            if(tb!=0){
                ttv=(tb-(av-tv))>0?av:(tb+tv);
                tta=ta;
                ttb=(tb-(av-tv))>0?(tb-(av-tv)):0;
                if(!Hash[ttv][tta][ttb]){
                    if(ttv==av/2&&(tta==av/2||ttb==av/2))
                        return tt+1;
                    Hash[ttv][tta][ttb]=true;
                    temp.set(ttv,tta,ttb,tt+1);
                    cap.push(temp);
                }
            }
        }
        cap.pop();
    }
    return -1;
}

int main()
{
    while(cin>>av>>aa>>ab,av||aa||ab){
        if(av&1){
            cout<<"NO"<<endl;
            continue;
        }
        memset(Hash,false,sizeof(Hash));
        Hash[av][0][0]=true;
        while(!cap.empty()) cap.pop();
        coke temp(av,0,0,0);
        cap.push(temp);
        int ans=Bfs(av);
        if(ans!=-1) cout<<ans<<endl;
        else cout<<"NO"<<endl;
    }
}